#FLAGS
CFLAGS  = gcc -Wall -g -I .\include
OBJ 	= -c
OUT 	= -o .\bin\test
SRC		= .\src\\
 
all: main clean

#BINARY FILE
main: screen.o point.o ldalg.o
	$(CFLAGS) $(SRC)main.c screen.o point.o ldalg.o $(OUT)
 
#OBJECT FILES
ldalg.o: 
	$(CFLAGS) $(OBJ) $(SRC)ldalg.c 

point.o: 
	$(CFLAGS) $(OBJ) $(SRC)point.c 

screen.o: 
	$(CFLAGS) $(OBJ) $(SRC)screen.c 

#CLEAN .o FILES
clean:
	del /S *.o