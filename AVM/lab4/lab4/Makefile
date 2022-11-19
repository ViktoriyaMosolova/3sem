FLAG = -Wall -Werror -Wextra
CC = gcc
SRC = lab41.c
Q1 = lab41

all: lab41

lab41: lab41.c
	$(CC) $(FLAG) $(SRC) -o $(Q1)
	./lab41.exe

clean: 
	rm -rf $(Q1) *.o *.out

rebuild: clean all
