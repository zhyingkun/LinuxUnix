#include <iostream>
using namespace std;

int globalInt = 42;

void printHello(int num){
	cout<<"Hello World: "<<num<<" globalInt: "<<globalInt<<endl;
}

int main(int argc, char* argv[]){
	printHello(23);
	return 0;
}
