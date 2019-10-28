#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "vetor.h"

struct NoL
{
	vetor* planetsArray;
	int mesEnum;
	NoL* dir;
	NoL* esq;
};

class lista
{
private:
	NoL* sentinela;

	//Tamanho da lista
	int cardinalidade_;

public:
	//Cria uma lista vazia
	lista();

	//Adiciona elemento à lista
	void addElement(vetor& planetsArray, int mesEnum);

	//Printa a lista, enviando qual o mês correspondente do vetor de planetas contido no Nó
	void printL();

	//Destrutor da lista
	~lista();
};

#endif //LISTA_H
