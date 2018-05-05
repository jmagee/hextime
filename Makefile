cc=cc
cflags=-O2 -Wall -Wextra

all: hextime

hextime: hextime.c
	$(cc) $(cflags) $< -o $@

.PHONY: clean

clean:
	rm -fv hextime
