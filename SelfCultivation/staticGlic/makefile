staticGlibc.dump: staticGlibc
	objdump -s -D $^ > $@

staticGlibc: staticGlibc.c
	gcc -m32 -static -o $@ $^
