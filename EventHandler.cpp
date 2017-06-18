#include "EventHandler.h"
#include <stdio.h>
namespace Antinus{
namespace Eventmedia{
pthread_mutex_t take_event = PTHREAD_MUTEX_INITIALIZER;
volatile int trigered = 0;
list<Event>* event_queue = new list<Event>();
}
}

using namespace Antinus;

HANDLER_INI HANDLER_INI_III;

HANDLER_INI::~HANDLER_INI(){
	delete Eventmedia::event_queue;
}

EventHandler::EventHandler(unsigned long Event_to_Handle){
	slot_func_event = new map<Event,executer*>(Event_to_Handle);
	time_to_stop = false;
}

EventHandler::~EventHandler(){
	delete slot_func_event;
}


void EventHandler::StartListen(){
	int rc;
	rc = pthread_create(&(this->listener), NULL, Listen, this);
	if(rc != 0)
		return;
}

void EventHandler::Stop(){
	time_to_stop = true;
}

void* EventHandler::Listen(void* obj){
	EventHandler* this_obj = (EventHandler*)obj;
	unsigned long i;
	unsigned long len;
	Event tmp;
	executer* exec;
	while(1){
		if(this_obj->time_to_stop){
			return nullptr;
		}
		if(Eventmedia::trigered){
       		len = Eventmedia::event_queue->length();
       		printf("we have events now:%d\n",len);
       		i = 0;
       		while(i < len){
       			tmp = Eventmedia::event_queue->Query(i);
       			if(this_obj->slot_func_event->Find(tmp)){
       				if (pthread_mutex_lock(&Eventmedia::take_event) != 0) {
							printf("lock failed!\n");
            				return nullptr;
       				}
       				Eventmedia::trigered -= 1;
       				Eventmedia::event_queue->Delete(i);
       				if (pthread_mutex_unlock(&Eventmedia::take_event) != 0) {
       					printf("unlock failed!\n");
            			return nullptr;
        			}
       				exec = this_obj->slot_func_event->Query(tmp);

       				(*exec)();
       				break;
       			}
       			i++;
       		}    		
		}
	}
}