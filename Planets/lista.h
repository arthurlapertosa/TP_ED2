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

	//Adiciona elemento � lista
	void addElement(vetor& planetsArray, int mesEnum);

	//Printa a lista, enviando qual o m�s correspondente do vetor de planetas contido no N�
	void printL();

	//Destrutor da lista
	~lista();
};

#endif //LISTA_H
