CC = gcc
CFLAGS = -g -Wall -O0

INC = ./include

OBJS = linked_list.o

$(OBJS): linked_list.c linked_list.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

