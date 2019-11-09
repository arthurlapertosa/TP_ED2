CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp2 # nome do executavel que sera gerado, nao troque
TMPOUT=tp2.testresult

$(EXEC): main.cpp planets.o lista.o vetor.o
	$(CC) $(CFLAGS) main.cpp planets.o lista.o vetor.o -o $(EXEC)

planets.o: planets.cpp
	$(CC) $(CFLAGS) -c planets.cpp -o planets.o

lista.o: lista.cpp
	$(CC) $(CFLAGS) -c lista.cpp -o lista.o

laboratorio.o: vetor.cpp
	$(CC) $(CFLAGS) -c vetor.cpp -o vetor.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf planets.o
	rm -rf lista.o
	rm -rf vetor.o

