namespace Antinus{

template<function_register & fr>
void EventHandler::bind_event_and_function(Event & ev,function<fr> & func){
	slot_func_event->Write(ev,&func);
}





}