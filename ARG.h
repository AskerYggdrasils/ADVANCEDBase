#ifndef _ARG_H_
#define _ARG_H_

namespace Antinus{
	
class ARG{
	public:
		long int int_arg;
		char* string_arg;
		double real_arg;
	public:
		void operator = (long int a);
		void operator = (char* a);
		void operator = (double a);
		void operator = (ARG& another);
	public:
		ARG();
		ARG(int a);
		ARG(char* a);
		ARG(const char* a);
		ARG(double a);
		~ARG();
};

}

#endif