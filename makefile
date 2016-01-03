CC = gcc
CFLAGS = -Wall

TARGETS = shell

default: shell

all: $(TARGETS)

shell: shell.o dirutils.o parsing.o shutility.o hcommand.o
	$(CC) $(CFLAGS) shell.o dirutils.o parsing.o shutility.o hcommand.o -o shell

clean:
	rm -f *.o *~ a.out $(TARGETS)

.c.o:
	$(CC) $(CFLAGS) -c $<

