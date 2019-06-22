CC = gcc
CFLAGS = -g -Wall -O0

INC = ./include

OBJS = linked_list.o
EXEC = main

$(EXEC): main.c $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $^ -o $(EXEC)

$(OBJS): linked_list.c linked_list.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) *.o $(EXEC)
