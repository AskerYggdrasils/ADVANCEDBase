CXXFLAGS+=-std=c++11
CXXFLAGS+=-lpthread
obj=ARG.o function_register.o Event.o EventHandler.o
#argparser.o 
drive:drive.cpp ../IOBase/libIOBase.a libADVANCEDBase.a
libADVANCEDBase.a: $(obj) ADVANCEDBase.h function.h
	ar -rcs libADVANCEDBase.a $(obj)
#argparser.o:argparser.h
ARG.o:ARG.h
function_register.o:function_register.h
EventHandler.o:EventHandler.h
Event.o:Event.h
.PHONY:clean
clean:
	rm $(obj) 
