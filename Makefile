all: base64.o

base64.o: base64.c
	gcc -Wall -Wextra -c base64.c

clean:
	rm -rf *.o
