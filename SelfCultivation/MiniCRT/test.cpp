#include "iostream"
#include "string"
using namespace std;

class Test {
private:
	int age;
	char* name;
public:
	Test(int age, char* name);
	~Test();
	void printHello(char* hello);
};
Test::Test(int age, char* name){
	this->age = age;
	this->name = name;
}
Test::~Test(){

}
void Test::printHello(char* hello){
	cout<<hello<<" age:"<<this->age<<" name:"<<this->name<<endl;
}

int main(int argc, char* argv[]){
	Test* myTest = new Test(26, "zyk");
	myTest->printHello("Hello World!");
	delete myTest;
	return 0;
}
