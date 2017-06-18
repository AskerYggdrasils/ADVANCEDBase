#include "argparser.h"
#define ARGPARSER(return_type) template<function_register func> return_type argparser<func_name>::
#define constructor(para) template<function_register func> argparser<func_name>::argparser(para)
#define destructor() template<function_register func> argparser<func_name>::~argparser()

using namespace Antinus;

ARGPARSER(void) parse(int argc,char* argv[]){


	/* sth */
		argparser_on_wrong_option();
	
}














