FLAG = -Wall -Werror -Wextra
CC = gcc
SRC = rgr.c
Q1 = rgr

all: rgr

rgr: rgr.c
	$(CC) $(FLAG) $(SRC) -o $(Q1)
	./rgr.exe

clean: 
	rm -rf $(Q1) *.o *.out

rebuild: clean all
