CC = gcc
CFLAGS = -g -Wall -O0

INC = ./include

OBJS = linked_list.o main.o
EXEC = main

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $^ -o $(EXEC)

linked_list.o : linked_list.c linked_list.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) *.o $(EXEC)
