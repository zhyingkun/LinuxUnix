all: libabc.so libab.so liba.so libb.so libcc.so

libabc.so: a.c b.c c.c
	gcc -shared -fPIC $^ -o $@

libab.so: a.c b.c
	gcc -shared -fPIC $^ -o $@

liba.so: a.c
	gcc -shared -fPIC $^ -o $@

libb.so: b.c
	gcc -shared -fPIC $^ -o $@

libcc.so: c.c
	gcc -shared -fPIC $^ -o $@

clean:
	rm *.so
