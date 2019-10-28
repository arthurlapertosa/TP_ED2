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

	//Capacidade máxima do vetor
	int capacity_;

	//Contém o vetor com todos os elementos
	elements* elements_;
public:
	//Cria um vetor com tamanho máximo de "capacity"
	vetor(int capacity);

	//Retorna o elemento da posição index
	elements& operator[](int index) const;

	//Adiciona um novo elemento ao vetor
	void pushback(elements& element);

	//Cria e adiciona um novo elemento ao vetor
	void pushbackEl(std::string name, int integer);

	//Printa somente o vetor.
	void printArray() const;

	//Printa o vetor. Recebe o mês de visitação como parâmetro (para ser impresso juntamente, na frente de cada elemento)
	void printArray(int mes) const;

	//Retorna a capacidade máxima do vetor
	int capacity() const;

	//Retorna o tamanho do vetor
	int size() const;

	//Organiza o vetor em ordem crescente de "stayTime"
	void sort();

	//Destrutor da classe
	~vetor();

private:
	void mergeSort(elements aux[], int esq, int dir);

	void merge(elements aux[], int esq, int meio, int dir);
};

#endif //VETOR_H