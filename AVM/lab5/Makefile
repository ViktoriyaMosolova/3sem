FLAG = -Wall -Werror -Wextra
CC = gcc
SRC = lab5.c
Q1 = lab5

all: lab5

lab5: lab5.c
	$(CC) $(FLAG) $(SRC) -o $(Q1)
	./lab5.exe

clean: 
	rm -rf $(Q1) *.o *.out

rebuild: clean all
