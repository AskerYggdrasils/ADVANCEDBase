#include "EventHandler.h"
#include "../IOBase/IOBase.h"
#include "../DEBUGBase/Debug.h"
#include <unistd.h>
using namespace Antinus;
function_register a(1);

namespace Antinus{
template<>
void function<a>::operator()(){
	//termout << "Hello Handler!" << "\n";
}
}
using namespace Antinus;
int main(int argc,char* argv[])
{
	EventHandler Handler_1;
	EventHandler Handler_2;
	EventHandler Handler_3;
	function<a> func_1;
	Event input_hello("Input_hello");
	Handler_1.bind_event_and_function<a>(input_hello,func_1);
	Handler_1.StartListen();
	//Handler_2.bind_event_and_function<a>(input_hello,func_1);
	//Handler_2.StartListen();
	//Handler_3.bind_event_and_function<a>(input_hello,func_1);
	//Handler_3.StartListen();
	while(1){
		input_hello.Triger();
		usleep(100);
	}
	return 0;
}