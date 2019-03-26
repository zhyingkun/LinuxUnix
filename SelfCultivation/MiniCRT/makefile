all: minicrt.a test

minicrt.a: malloc.o printf.o stdio.o string.o atexit.o ctors.o crtbegin.o crtend.o
	ar -rs $@ $^
#	rm -rf *.o

%.o: %.c
	gcc -m32 -ggdb -c -fno-builtin -nostdlib -fno-stack-protector $^ -o $@

test: entry.o test.o minicrt.a
	ld -m elf_i386 -static -e mini_crt_entry $^ -o $@
#	rm -rf *.o

clean:
	rm -rf *.o *.a test test.txt
