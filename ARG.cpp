#include "ARG.h"


using namespace Antinus;

ARG::ARG(){
	string_arg = nullptr;
}

ARG::ARG(int a){
	int_arg = a;
	string_arg = nullptr;
}

ARG::ARG(char* a){
	unsigned long i = 0;
	string_arg = new char[i];
	i = 0;
	while(a[i]){
		string_arg[i] = a[i];
		i++;
	}
}

ARG::ARG(const char* a){
	unsigned long i = 0;
	string_arg = new char[i];
	i = 0;
	while(a[i]){
		string_arg[i] = a[i];
		i++;
	}
}

ARG::ARG(double a){
	real_arg = a;
	string_arg = nullptr;
}

ARG::~ARG(){
	delete [] string_arg;
}

void ARG::operator = (long int a){
	int_arg = a;
}

void ARG::operator = (char* a){
	delete [] string_arg;
	unsigned long i = 0;
	while(a[i]){
		i++;
	}
	string_arg = new char[i];
	i = 0;
	while(a[i]){
		string_arg[i] = a[i];
		i++;
	}
}

void ARG::operator = (double a){
	real_arg = a;
}

void ARG::operator = (ARG& another){
	char* a = another.string_arg;
	delete [] string_arg;
	if(a != nullptr){
		unsigned long i = 0;
		while(a[i]){
			i++;
		}
		string_arg = new char[i];
		i = 0;
		while(a[i]){
			string_arg[i] = a[i];
			i++;
		}
	}
	else{
		string_arg = nullptr;
	}
	this->int_arg = another.int_arg;
	this->real_arg = another.real_arg;
}