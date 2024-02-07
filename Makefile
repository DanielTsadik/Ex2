CC = gcc
CFLAGS = -Wall
AR = ar 

all: connections connections0

connections: my_graph.o my_mat.a 
	$(CC) $(CFLAGS) -o connections my_graph.o my_mat.a 

my_mat.a: my_mat.o
	$(AR) -rcs my_mat.a my_mat.o
#

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

connections0: my_Knapsack.o 
	$(CC) $(CFLAGS) -o connections0 my_Knapsack.o

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c my_Knapsack.c

.PHONY: clean all 

clean: 
	rm -f *.o *.a connections