#include "VirtualBase/BASICBase/loop.h"
#define FUNCTION(return_type) template<function_register & func> return_type function<func>::
#define constructor(para) template<function_register & func> function<func>::function(para)
#define destructor() template<function_register & func> function<func>::~function()

#include <stdio.h>

namespace Antinus{

constructor(){
	this->num_of_args = func.num_of_args;
	this->paras = new ARG[this->num_of_args];
}

constructor(const function<func> & another){
	this->num_of_args = another.num_of_args;
	this->paras = new ARG[this->num_of_args];
	loop(another.num_of_args){
		this->paras[i] = another.paras[i];
	}
}

destructor(){
		delete [] this->paras;
}

FUNCTION(void) SetParas(ARG* paras){
	loop(this->num_of_args){
		this->paras[i] = paras[i];
	}
}

FUNCTION(void) operator = (const function<func> & another){
	this->num_of_args = another.num_of_args;
	delete [] this->paras;
	this->paras = new ARG[this->num_of_args];
	loop(another.num_of_args){
		this->paras[i] = another.paras[i];
	}
}

}

#undef FUNCTION
#undef constructor
#undef destructor


