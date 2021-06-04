
EXECUTAVEL=photoshop-in-c

CC     = gcc
CFLAGS = -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -g -fno-inline -fno-omit-frame-pointer
GLLIB = -lm

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Image.o 
	@echo Criando arquivo executável: $@
	@$(CC) main.o Image.o $(GLLIB) -o $(EXECUTAVEL) 

main.o: main.c
	@echo Compilando arquivo objeto: $@
	@$(CC) $(CFLAGS) -c main.c

Image.o: Image.c
	@echo Compilando arquivo objeto: $@
	@$(CC) $(CFLAGS) -c Image.c 

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

memcheck: $(EXECUTAVEL) 
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL) example.pnm

.PHONY: clean
clean:
	rm -f $(EXECUTAVEL) *.o