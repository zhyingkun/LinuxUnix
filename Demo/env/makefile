.PHONY: clean

all: usermode env_in_c env_cwd

usermode: usermode.c
	gcc -std=c11 -o $@ $^

env_in_c: env_in_c.c
	gcc -std=c11 -o $@ $^

env_cwd: env_cwd.c
	gcc -std=c11 -o $@ $^

clean:
	rm usermode env_in_c env_cwd
