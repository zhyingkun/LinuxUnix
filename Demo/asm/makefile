.PHONY: all clean

all: clang clang.objdump cpplang cpplang.objdump

clean:
	rm clang clang.objdump cpplang cpplang.objdump

clang: clang.c
	gcc -o $@ $^

clang.objdump: clang
	objdump -s -d $^ > $@

cpplang: cpplang.cpp
	g++ -o $@ $^

cpplang.objdump: cpplang
	objdump -s -d $^ > $@
