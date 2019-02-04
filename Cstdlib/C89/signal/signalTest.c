#include <signal.h>

typedef void (*SignalFunc)(int);

int gNum = 0;

void sigAbrtFunc(int sig){
	gNum += sig;
}

int main(int argc, char* argv[]){
	// SIGABRT
	// SIGTERM
	// SIGILL
	// SIGINT
	// SIGSEGV
	// SIGFPE

	// Default Handler
	// SIG_DFL
	// SIG_ERR
	// SIG_IGN

	SignalFunc oldFunc = signal(SIGABRT, sigAbrtFunc);
	SignalFunc oldTerm = signal(SIGTERM, sigAbrtFunc);
	int ret = raise(SIGABRT);
	int num = raise(SIGTERM);

	return gNum;
}