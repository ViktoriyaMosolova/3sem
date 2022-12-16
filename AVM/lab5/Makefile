FLAG = -Wall -Werror -Wextra
CC = g++
SRC = lab5.cpp
Q1 = lab5

all: lab5

lab5: lab5.cpp
	$(CC) $(FLAG) $(SRC) -o $(Q1)
	./lab5.exe

clean: 
	rm -rf $(Q1) *.o *.out

rebuild: clean all
