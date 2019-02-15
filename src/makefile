CC  = gcc
INC = -I ..\include
OBJ = -c
OUT = -o ..\bin\dda
WAL = -Wall

all: main clean

main: screen.o dda.o
	$(CC) main.c screen.o dda.o $(OUT) $(INC) $(WAL)

dda.o: 
	$(CC) $(OBJ) dda.c $(INC) $(WAL)

screen.o: 
	$(CC) $(OBJ) screen.c $(INC) $(WAL)

#clean .o files
clean:
	del screen.o dda.o