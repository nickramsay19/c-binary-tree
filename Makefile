all: main

main: build/main.o build/Tree.o build
	gcc -o main build/main.o build/Tree.o

build:
	mkdir build

build/main.o: src/main.c build
	gcc -o build/main.o -c src/main.c

build/Tree.o: src/Tree.c build
	gcc -o build/Tree.o -c src/Tree.c 

clean:
	rm build/* main
