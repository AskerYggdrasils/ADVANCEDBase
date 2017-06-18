#ifndef _EVENT_H_
#define _EVENT_H_

namespace Antinus{

class Event{
	friend class EventHandler;
private:
	char* name;
 	bool trigered;
public:
	Event();
	Event(const char*);
	Event(const Event & another);
	Event(Event && another);
	~Event();
public:
	void Triger();
	char* GetName();
public:
	bool operator == (Event & another);
	void operator = (const Event & another);
	void operator = (Event && another);
};


}

#endif