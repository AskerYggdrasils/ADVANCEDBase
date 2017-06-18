#include "function_register.h"

#define constructor(para) function_register::function_register(para)
#define destructor() function_register::~function_register()

using namespace Antinus;

constructor(unsigned long num_of_args){
	this->num_of_args = num_of_args;
}


