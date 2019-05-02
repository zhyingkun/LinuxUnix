.PHONY: clean run

all: Coroutine CSharpCoroutine.exe

Coroutine: Coroutine.c
	gcc $^ -o $@

CSharpCoroutine.exe: CSharpCoroutine.cs
	mcs -out:$@ $^

clean:
	rm -rf Coroutine CSharpCoroutine.exe

run: Coroutine CSharpCoroutine.exe
	echo "Run C Coroutine Now:"
	./Coroutine
	echo ""
	echo "Run JS Coroutine Now:"
	node ./NodejsCoroutine.js
	echo ""
	echo "Run Lua Coroutine Now:"
	lua ./LuaCoroutine.lua
	echo ""
	echo "Run C# Coroutine Now:"
	mono ./CSharpCoroutine.exe
