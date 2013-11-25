CC=gcc
CFLAGS=-std=c99 -Wall -pedantic
LFLAGS=-lglfw3 -lGLU -lX11 -lpthread -lrt -lXrandr -lXi -lXxf86vm -lrt -lm -lGL -lXrandr -lXi -lXxf86vm -lm -lGL

all: train1 train2 train3 train4

train1: train1.c
	$(CC) -o train1 $(CFLAGS) train1.c $(LFLAGS)
train2: train2.c
	$(CC) -o train2 $(CFLAGS) train2.c $(LFLAGS)
train3: train3.c
	$(CC) -o train3 $(CFLAGS) train3.c $(LFLAGS)
train4: train4.c
	$(CC) -o train4 $(CFLAGS) train4.c $(LFLAGS)
clean:
	rm train1 train2 train3 train4
