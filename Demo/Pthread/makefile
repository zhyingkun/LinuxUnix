.PHONY: run clean

all: pthreadTest mainExit thread

pthreadTest: pthreadTest.c
	gcc -std=c99 $^ -o $@ -lpthread

mainExit: mainExit.c
	gcc $^ -std=c99 -o $@ -lpthread

thread: thread.c
	gcc $^ -std=c99 -o $@ -lpthread

run: mainExit
	./mainExit

clean:
	rm -rf pthreadTest mainExit thread

