CC=gcc
CFLAGS=-O -Wall -std=c17 -pedantic

all: bat

bat_sources := *.c
bat: $(bat_sources)
	$(CC) $(CFLAGS) -o bat $(bat_sources)

clean:
	rm -f bat

distclean:
	clean
