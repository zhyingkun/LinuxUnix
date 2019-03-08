a.out: lex.yy.c fb1-5.tab.c
	gcc -o $@ -std=c11 $^ -ll

lex.yy.c: fb1-5.l
	flex -o $@ $^

fb1-5.tab.c: fb1-5.y
	bison -d $^

clean:
	rm a.out lex.yy.c fb1-5.tab.c fb1-5.tab.h
