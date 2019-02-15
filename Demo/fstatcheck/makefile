all: fstatcheck_wrap fstatcheck

fstatcheck: fstatcheck.c
	gcc -std=c11 -o $@ $^

fstatcheck_wrap: fstatcheck_wrap.c
	gcc -std=c11 -o $@ $^

clean:
	rm fstatcheck_wrap fstatcheck