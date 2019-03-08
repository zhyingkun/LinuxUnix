main: main.c
	gcc $^ -labc -ldl -L./ -Wl,-rpath,./ -g -o $@

# if use -L./ ,then ./ dir must not contain some .so file which has the same name with std .so files
