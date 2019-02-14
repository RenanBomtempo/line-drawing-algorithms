CC  = gcc
INC = -I ..\include
OBJ = -c
OUT = -o ..\bin\dda
WAL = -Wall

all: main clean

main: display.o
	$(CC) main.c display.o $(OUT) $(INC) $(WAL)

display.o: 
	$(CC) $(OBJ) display.c $(INC) $(WAL)

#clean .o files
clean:
	del display.o