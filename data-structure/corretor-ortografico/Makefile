CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow
LIBS=-lm
EXECUTAVEL=EP3

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Util.o Avl.o Bintree.o Fila.o
	gcc main.o Util.o Avl.o Bintree.o Fila.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Util.o: Util.c
	gcc $(CFLAGS) -c Util.c

Avl.o: Avl.c
	gcc $(CFLAGS) -c Avl.c

Bintree.o: Bintree.c
	gcc $(CFLAGS) -c Bintree.c

Fila.o: Fila.c
	gcc $(CFLAGS) -c Fila.c

clean: 
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL) -d Dicionario.txt -t TextoExemplo.txt
	
run: $(EXECUTAVEL) 
	./$(EXECUTAVEL) -d Dicionario.txt -t TextoExemplo.txt