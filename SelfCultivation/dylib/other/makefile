all:
	gcc -fPIC -c libsrc/a.c -o build/a.o
	gcc -fPIC -c libsrc/b.c -o build/b.o
	ar rsc -o static/libab.a build/a.o build/b.o
	gcc -fPIC -shared -o libab.so dynamic/dylib.c static/libab.a
	gcc -o mainWithStatic main.c static/libab.a
	gcc -o mainWithDylib main.c -L. -lab
