.PHONY: all clean

all: libvector.a libvector.so dll main2 main2dll

libvector.a: addvec.o multvec.o
	ar rcs $@ $^

libvector.so: addvec.c multvec.c
	gcc -shared -fpic -o $@ $^

dll: dll.c
	gcc -rdynamic -o $@ $^ -ldl

main2: main2.c
	gcc -static -Wall -g -o $@ $^ -L. -lvector

main2dll: main2.c
	gcc -Wall -g -o $@ $^ -L. -lvector

%.o: %.c
	gcc -Wall -g -c $^ -o $@

clean:
	rm addvec.o multvec.o libvector.a libvector.so dll main2 main2dll
