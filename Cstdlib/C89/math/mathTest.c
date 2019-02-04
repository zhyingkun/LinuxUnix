#include <math.h>

#include <stdio.h>

int main(int argc, char* argv[]){
	printf("sin 30: %f\n", sin(M_PI/6)); // 30 deg
	printf("asin 0.5: %f\n", asin(0.5)*180/M_PI);
	// cos
	// acos
	// tan
	// atan
	// atan2
	// sinh
	// cosh
	// tanh
	// exp // e^x
	// frexp
	// ldexp
	// log
	// log10
	// modf
	// pow
	// sqrt
	// ceil
	// fabs
	// floor
	// fmod

	// printf("LC_COLLATE: %d\n", LC_COLLATE);
	// printf("LC_CTYPE: %d\n", LC_CTYPE);
	// printf("LC_MONETARY: %d\n", LC_MONETARY);
	// printf("LC_NUMERIC: %d\n", LC_NUMERIC);
	// printf("LC_TIME: %d\n", LC_TIME);
	// printf("LC_MESSAGES: %u\n", LC_MESSAGES);

	// char* new_LC_CTYPE = setlocale(LC_CTYPE, "C");
	// printf("new_LC_CTYPE: %s\n", new_LC_CTYPE);
	// struct lconv* lConv = localeconv();
	// printf("decimal_point: %s\n", lConv->decimal_point);
	// printf("currency_symbol: %s\n", lConv->currency_symbol);
	
	return 0;
}