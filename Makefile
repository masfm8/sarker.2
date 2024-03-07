CC=gcc
CFLAGS = -Wall -std=c99

all: oss worker

oss: oss.c
	$(CC) $(CFLAGS) oss.c -o oss -lrt

worker: worker.c
	$(CC) $(CFLAGS) worker.c -o worker

clean:
	rm -f oss worker
