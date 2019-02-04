#include <ctype.h>

int main(int argc, char* argv[]){
	int a = isalnum('a');   // is alpha or number
	int b = isalpha('b');   // is alpha
	int c = iscntrl('\t');  // is control character
	int d = isdigit('3');   // is decimal-digit character 
	int e = isgraph('E');   // any printing character except space ' '
	int f = islower('f');   // is lower case letter
	int g = isprint(' ');   // any printing character including space ' '
	int h = ispunct(' ');   // any printing character that is neither space ' ' nor a character for which isalnum is true
	int i = isspace('\n');  // ' ', '\f', '\n', '\r', '\t', '\v'
	int j = isupper('A');   // is upper case letter
	int k = isxdigit('b');  // any hexadecimal-digit character
	int l = tolower('C');   // upper case to lower case
	int m = toupper('c');   // lower case to upper case
	return k;
}