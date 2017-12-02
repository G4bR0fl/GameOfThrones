# Para compilar tudo bonitinho, use o seguinte comando ,no terminal, dentro do diretório: 'make all'
# Para remover os '.o' e o arquivo executavel, execute no terminal o comando: 'make clean' 


all: compile

compile: main.o got.o
	gcc -g -o main main.o got.o

main.o: main.c
	gcc -g -c main.c

got.o: got.c
	gcc -g -c got.c

clean:
	rm -rf *o main
