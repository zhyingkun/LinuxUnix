TinyHello: TinyHello.o
	# ld -melf_i386 -static -e nomain -o $@ $^
	ld -melf_i386 -static -T TinyHello.lds -o $@ $^

TinyHello.o: TinyHello.c
	gcc -m32 -c -fno-builtin $^
