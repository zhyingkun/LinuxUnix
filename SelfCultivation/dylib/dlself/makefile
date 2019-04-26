.PHONY: run clean

all: dlself

dlself: main.c
	gcc $^ -o $@ -rdynamic -ldl
	objdump -T $@
	#readelf --dyn-syms $@

run: dlself
	./dlself

clean:
	rm -rf dlself

