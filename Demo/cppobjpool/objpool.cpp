#include <stdio.h>
#include <stdlib.h>
#include <new>
using namespace std;

#define LIST_LENGTH 16
class objpool{
private:
	static int freeLen;
	static void* freeList[LIST_LENGTH];
public:
	static void* operator new(size_t size){
		printf("Operator new freeLen: %d\n", freeLen);
		if(freeLen == 0){
			return malloc(size);
		}
		return freeList[--freeLen];
	}
	static void operator delete(void* p){
		if(freeLen == LIST_LENGTH){
			free(p);
		}
		freeList[freeLen++] = p;
		printf("Operator delete freeLen: %d\n", freeLen);
	}

private:
	int tmpInt;
	const char* tmpCharP;
public:
	objpool(){}
	objpool(int tmp, const char* tmpC){
		this->tmpInt = tmp;
		this->tmpCharP = tmpC;
	}
	void printData(){
		printf("obj:%x int:%d char*:%s\n", this, this->tmpInt, this->tmpCharP);
	}
};
int objpool::freeLen = 0;
void* objpool::freeList[LIST_LENGTH];

int main(int argc, char* argv[]){
	objpool* tmp1 = new objpool(12, "Test");
	tmp1->printData();
	delete tmp1;
	objpool* tmp2 = new objpool();
	tmp2->printData();
	delete tmp2;
	return 0;
}
