CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o ferry.o

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)
main.o: main.c ferry.h status.h
	$(CC) $(CFLAGS) -c main.c -o main.o
ferry.o: ferry.h ferry.c status.h
	$(CC) $(CFLAGS) -c ferry.c -o ferry.o

clean:
	rm main $(OBJECTS)