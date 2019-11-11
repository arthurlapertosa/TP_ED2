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

	//Capacidade maxima do vetor
	int capacity_;

	//Contem o tamanho da string.
	int stringsize_;

	//Contem o vetor com todos os elementos
	elements* elements_;
public:
	//Cria um vetor com tamanho maximo de "capacity"
	vetor(int capacity, int stringSize);

	//Retorna o elemento da posicao index
	elements& operator[](int index) const;

	//Adiciona um novo elemento ao vetor
	void pushback(elements& element);

	//Cria e adiciona um novo elemento ao vetor
	void pushbackEl(std::string name, int integer);

	//Printa somente o vetor.
	void printArray() const;

	//Printa o vetor. Recebe o mes de visitacao como parametro (para ser impresso juntamente, na frente de cada elemento)
	void printArray(int mes) const;

	//Retorna a capacidade maxima do vetor
	int capacity() const;

	//Retorna o tamanho do vetor
	int size() const;

	//Organiza o vetor em ordem crescente de "stayTime"
	void sort();

	//Organiza o vetor em ordem crescente de "nome"
	void sortName();

	//Destrutor da classe
	~vetor();

private:
	void mergeSort(elements aux[], int esq, int dir);

	void merge(elements aux[], int esq, int meio, int dir);

	//Metodo radixSort
	void radixSort();

	//Faz o counting sort dos elementos na posicao "index" dos nomes dos planetas - usado para fazer o radix sort.
	void countingSortChar(int index);
};

#endif //VETOR_H