#include "EventHandler.h"
#include "string.h"
using namespace Antinus;

Event::Event(){
	name = nullptr;
}

Event::Event(const char* name){
	unsigned long i = 0;
	while(name[i]){
		i++;
	}
	this->name = new char[i];
	i = 0;
	while(name[i]){
		this->name[i] = name[i];
		i++;
	}
}

Event::Event(const Event & another){
	unsigned long i = 0;
	while(another.name[i]){
		i++;
	}
	this->name = new char[i];
	i = 0;
	while(name[i]){
		this->name[i] = another.name[i];
		i++;
	}
}

Event::Event(Event && another){
	this->name = another.name;
	another.name = nullptr;
}

Event::~Event(){
	delete [] name;
}

void Event::Triger(){
	Eventmedia::event_queue.Append(*this);
	Eventmedia::trigered += 1;
}

char* Event::GetName(){
	return name;
}

bool Event::operator == (Event & another){
	return !strcmp(this->name,another.name);
}

void Event::operator = (const Event & another){
	unsigned long i = 0;
	while(another.name[i]){
		i++;
	}
	this->name = new char[i];
	i = 0;
	while(name[i]){
		this->name[i] = another.name[i];
		i++;
	}
	
}

void Event::operator = (Event && another){
	this->name = another.name;
	another.name = nullptr;
}

template <> 
unsigned long HashTable<Event>::Hash(Event ev){
	unsigned long hs = 0; 
	char* str = ev.GetName();
	while(*str) {
	    hs = (hs + (*str << 4) + (*str++ >> 4)) * 11;
	}
	return hs % TableSize;
}