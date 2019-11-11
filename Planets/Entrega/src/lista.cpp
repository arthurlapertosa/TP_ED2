#include "lista.h"

lista::lista()
{
	sentinela = new NoL;
	cardinalidade_ = 0;
	sentinela->planetsArray = NULL;
	sentinela->dir = sentinela;
	sentinela->esq = sentinela;

}

void lista::addElement(vetor& planetsArray, int mesEnum)
{
	NoL* novo = new NoL;
	novo->planetsArray = &planetsArray;
	novo->mesEnum = mesEnum;
	novo->esq = sentinela;
	novo->dir = sentinela->dir;
	sentinela->dir->esq = novo;
	sentinela->dir = novo;
	if (cardinalidade_ == 0) {
		sentinela->esq = novo;
	}
	cardinalidade_++;
}

void lista::printL()
{
	NoL* i;
	for (i = sentinela->esq; i != sentinela; i = i->esq) {
		i->planetsArray->printArray(i->mesEnum);
	}
}

lista::~lista()
{
	NoL* i = sentinela->dir;
	NoL* iProx;
	while (i != sentinela) {
		iProx = i->dir;
		delete i;
		i = iProx;
	}
}
