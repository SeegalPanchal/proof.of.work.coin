# Seegal Panchal

CC = g++
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude
LDFLAGS = -L~/bin

all: main

main: src/main.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/main.cpp -o bin/main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) bin/main.o -o bin/main

run: bin/main
	./bin/main

clean:
	rm -f bin/main bin/*.o bin/*.so core