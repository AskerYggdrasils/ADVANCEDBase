#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "function_register.h"
#include "executer.h"

namespace Antinus{

template<function_register & func>
class function:public executer{
private:
	unsigned long num_of_args;
	ARG* paras;
public:
	void SetParas(ARG* paras);
	void operator ()();
public:
	function();
	function(const function<func> & another);
	~function();
public:
	void operator = (const function<func> & another);
};

}

#include "function.inl"
#endif