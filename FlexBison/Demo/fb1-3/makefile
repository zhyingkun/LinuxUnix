a.out: lex.yy.c
	gcc -o $@ $^ -ll

lex.yy.c: fb1-3.l
	flex -o $@ $^

clean:
	rm a.out lex.yy.c
