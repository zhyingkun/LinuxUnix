#include "iostream"
#include "string"
using namespace std;

class Test {
private:
	int age;
	const char* name;
public:
	Test(int age, const char* name);
	~Test();
	void printHello(const char* hello);
};
Test::Test(int age, const char* name){
	this->age = age;
	this->name = name;
}
Test::~Test(){

}
void Test::printHello(const char* hello){
	cout<<hello<<" age:"<<this->age<<" name:"<<this->name<<endl;
}

int main(int argc, char* argv[]){
	Test* myTest = new Test(26, "zyk");
	myTest->printHello("Hello World!");
	delete myTest;
	return 0;
}
