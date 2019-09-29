# Seegal Panchal

CC = g++
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude
LDFLAGS = -L~/bin 

all: main

main: src/main.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/main.cpp -o bin/main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/sha256.cpp -o bin/sha256.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/block.cpp -o bin/block.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) bin/main.o bin/sha256.o bin/block.o -o bin/main

run: bin/main
	./bin/main

git-%:
	git add .
	git commit -m "$(@:git-%=%)"
#	git config credential.helper store
#	git config --global credential.helper 'cache --timeout 3600'
	git push

clean:
	rm -f bin/main bin/*.o bin/*.so core