OBJECTS = slist.o queue_test.o queue.o
TARGET = a.out
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
CC = gcc -g
HEAD = ../../include
VPATH = ../../test ../slist

a.out: ${OBJECTS}
	$(CC) $(CFLAGS) -o $@ $^
	
queue_test.o: queue_test.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I ${HEAD}

queue.o: queue.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I ${HEAD}
	
slist.o: slist.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I ${HEAD}
	
.PHONY: clean
clean:
	rm -f *.out *.o
	
