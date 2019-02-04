#include <float.h>

#include <stdio.h>

int main(int argc, char* argv[]){
	printf("DBL_MAX_10_EXP: %d\n", DBL_MAX_10_EXP);
	printf("DBL_DECIMAL_DIG: %d\n", DBL_DECIMAL_DIG);
	printf("DBL_MAX: %lf\n", DBL_MAX);
	printf("DBL_EPSILON: %lf\n", DBL_EPSILON);
	printf("DBL_MANT_DIG: %d\n", DBL_MANT_DIG);
	printf("DBL_MAX_EXP: %d\n", DBL_MAX_EXP);
	printf("DBL_MIN: %lf\n", DBL_MIN);
	printf("DBL_MIN_10_EXP: %d\n", DBL_MIN_10_EXP);
	printf("DBL_MIN_EXP: %d\n", DBL_MIN_EXP);
	printf("DBL_TRUE_MIN: %lf\n", DBL_TRUE_MIN);
	printf("FLT_MAX: %f\n", FLT_MAX);
	printf("LDBL_MAX: %Lf\n", LDBL_MAX);
	return 0;
}