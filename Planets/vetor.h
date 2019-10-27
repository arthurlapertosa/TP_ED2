#ifndef VETOR_H
#define VETOR_H
#include <string>
#include <iostream>

using std::cout;
using std::endl;

struct elements
{
	std::string planet;
	int stayTime;

	//Construtores auxiliares
	elements() : planet(" "), stayTime(0) { }
	elements(std::string planetName, int time) : planet(planetName), stayTime(time) { }
};


class vetor
{
private:
	//Tamanho atual do vetor de elementos
	int size_;

	//Capacidade m�xima do vetor
	int capacity_;

	//Cont�m o vetor com todos os elementos
	elements* elements_;
public:
	//Cria um vetor com tamanho m�ximo de "capacity"
	vetor(int capacity);

	//Retorna o elemento da posi��o index
	elements& operator[](int index) const;

	//Adiciona um novo elemento ao vetor
	void pushback(elements& element);

	//Cria e adiciona um novo elemento ao vetor
	void pushbackEl(std::string name, int integer);

	//Printa o vetor
	void printArray();

	//Retorna a capacidade m�xima do vetor
	int capacity();

	//Destrutor da classe
	~vetor();

};

#endif //VETOR_H