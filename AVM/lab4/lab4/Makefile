FLAG = -Wall -Werror -Wextra
CC = gcc
SRC = lab4.c
Q1 = lab4

all: lab4

lab4: lab4.c
	$(CC) $(FLAG) $(SRC) -o $(Q1)
	./lab4.exe

clean: 
	rm -rf $(Q1) *.o *.out

rebuild: clean all
