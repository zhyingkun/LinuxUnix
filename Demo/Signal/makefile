all: OutToTerSignal InFromTerSignal

OutToTerSignal: OutToTerSignal.c
	gcc -o $@ $^

InFromTerSignal: InFromTerSignal.c
	gcc -o $@ $^

cmd:
	stty tostop
	#nohup ./OutToTerSignal &
	strace ./OutToTerSignal &
	strace ./InFromTerSignal &

