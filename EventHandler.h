#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include "function.h"
#include "VirtualBase/ADTBase/map.h"
#include "Event.h"
#include <stdlib.h>
#include <pthread.h>
namespace Antinus{

template <> unsigned long HashTable<Event>::Hash(Event ev);

namespace Eventmedia{
extern pthread_mutex_t take_event;
extern volatile int trigered;
extern list<Event> event_queue;
}

class HANDLER_INI{
public:
	~HANDLER_INI();
};

extern HANDLER_INI HANDLER_INI_III;

class EventHandler{
friend class Event;
private:
	map<Event,executer*>* slot_func_event;
	Event break_ev;
	pthread_t listener;
	bool time_to_stop;
public:
	EventHandler(unsigned long Event_to_Handle = 307);	
	~EventHandler();
public:
	template<function_register& fr>
	void bind_event_and_function(Event& ev,function<fr>& fun);
	void StartListen();
	void Stop();
private:
	static void* Listen(void* obj);
};





}




#include "EventHandler.inl"
#endif