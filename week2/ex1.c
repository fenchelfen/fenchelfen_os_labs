#include <limits.h>				// sizes of integers types 
#include <float.h>				// characteristics of floating-point types
#include <stdio.h>

int main()
{
	int int_var;
	float fl_var;
	double d_var;

	int_var = INT_MAX;
	fl_var  = FLT_MAX;
	d_var   = DBL_MAX;

	printf("int\t%lu %d\n", sizeof(int_var), int_var);
	printf("float\t%lu %f\n", sizeof(fl_var), fl_var);
	printf("double\t%lu %f\n", sizeof(d_var), d_var);
	return 0;
}
