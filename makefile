Target: test
test: main.c postscript.c postscript.h
	gcc main.c postscript.c -lm -o test
	./test
