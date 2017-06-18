#ifndef _FUNCTION_REGISTER_
#define _FUNCTION_REGISTER_
#include "ARG.h"
namespace Antinus{

class function_register{
private:
	//static map<char*,int> register_table;
public:
	unsigned long num_of_args;
public:
	function_register(unsigned long num_of_args);
	//~function_register();
};


}



#endif