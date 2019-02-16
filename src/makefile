#FLAGS
CFLAGS  = gcc -Wall -g -I ..\include
OBJ 	= -c
OUT 	= -o ..\bin\test

all: main clean

#BINARY FILE
main: screen.o dda.o point.o
	$(CFLAGS) main.c screen.o dda.o point.o $(OUT)

#OBJECT FILES
dda.o: 
	$(CFLAGS) $(OBJ) dda.c

point.o: 
	$(CFLAGS) $(OBJ) point.c

screen.o: 
	$(CFLAGS) $(OBJ) screen.c

#CLEAN .o FILES
clean:
	del /S *.o