CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o sort.o

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)
main.o: main.c sort.h 
	$(CC) $(CFLAGS) -c main.c -o main.o
sort.o: sort.h sort.c 
	$(CC) $(CFLAGS) -c sort.c -o sort.o

clean:
	rm main $(OBJECTS)