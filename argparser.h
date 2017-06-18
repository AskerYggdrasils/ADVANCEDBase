#ifndef _ARGPARSER_H_ 
#define _ARGPARSER_H_

#include "VirtualBase/ADTBase/map.h"
#include "function.h"

namespace Antinus{
class argparser{
private:
	map<const char*,const char*>* option_arg;
	executer* on_wrong_option_func;
public:
	argparser();
	~argparser();
public:
	void regist_option(const char* option);
	void alias_option(const char* old_name,const char* new_name);
	void option_description(const char* option,const char* description);
	void on_wrong_option(function_register func);
	void parse(int argc,char* argv[]);
	const char* get_option_arg(const char* option);
};
}


#endif