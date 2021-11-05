cc=cc
cflags=-O2 -Wall -Wextra

all: hextime ctime

hextime: hextime.c
	$(cc) $(cflags) $< -o $@

ctime:
	@echo "#include <stdio.h>" > ctime.c
	@echo "#include <time.h>" >> ctime.c 
	@echo "int main(int argc, char *argv[printf(\"%ld%c\", time(NULL), 10)]) { return 0; }" >> ctime.c
	@$(cc) $(cflags) -Wno-unused-parameter ctime.c -o $@
	@rm ctime.c

.PHONY: clean

clean:
	rm -fv hextime ctime
