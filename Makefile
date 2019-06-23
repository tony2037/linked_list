CC = gcc
CFLAGS = -g -Wall -O0

INC = ./include

OBJS = linked_list.o
EXEC = main
KSORT = ksort

.PHONY: all
all: $(EXEC) $(KSORT)

$(EXEC): $(OBJS) main.o
	$(CC) $(CFLAGS) -I $(INC) $^ -o $@

$(KSORT): $(OBJS) ksort.o
	$(CC) $(CFLAGS) -I $(INC) $^ -o $@

linked_list.o : linked_list.c linked_list.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

ksort.o: ksort.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) *.o $(EXEC) $(KSORT)
