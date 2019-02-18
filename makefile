#FLAGS
CFLAGS  = gcc -Wall -g -I .\include
OBJ 	= -c
OUT 	= -o .\bin\test
SRC		= .\src\\
 
all: main clean

#BINARY FILE
main: screen.o dda.o point.o bresenham.o
	$(CFLAGS) $(SRC)main.c screen.o dda.o point.o bresenham.o $(OUT)
 
#OBJECT FILES
bresenham.o: 
	$(CFLAGS) $(OBJ) $(SRC)bresenham.c 

dda.o: 
	$(CFLAGS) $(OBJ) $(SRC)dda.c 

point.o: 
	$(CFLAGS) $(OBJ) $(SRC)point.c 

screen.o: 
	$(CFLAGS) $(OBJ) $(SRC)screen.c 

#CLEAN .o FILES
clean:
	del /S *.o