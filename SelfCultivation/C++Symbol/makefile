main: main.cpp
	g++ -g $^ -o $@
	objdump -s -D $@ > $@.dump

clean:
	rm -rf main main.dump main.dSYM
