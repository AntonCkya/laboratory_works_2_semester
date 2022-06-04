CC = gcc # компилятор
FL = -Wall -std=c99 -pedantic # флаги компилятору
OBJ = -c # флаг на получение .о файла
EXE = -o # флаг на получение исполняемого файла

lab23: main.o tree.o fruit.o
	$(CC) $(FL) $(EXE) lab23 main.o

main.o: main.c
	$(CC) $(FL) $(OBJ) main.c

tree.o: tree.c tree.h
	$(CC) $(FL) $(OBJ) tree.c

fruit.o: fruit.c fruit.h
	$(CC) $(FL) $(OBJ) fruit.c

clean:
	rm tree.o fruit.o main.o
