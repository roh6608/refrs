CC = gcc
CFLAGS = -O2 -Wall

all: compile

compile:
	$(CC) $(CFLAGS) -o ./bin/refrs ./src/main.c -lm

run: clean compile
	./bin/refrs

clean:
	rm ./bin/refrs
