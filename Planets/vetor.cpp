#include "vetor.h"

vetor::vetor(int capacity)
{
	this->elements_ = new elements[capacity];
	this->size_ = 0;
	this->capacity_ = capacity;
}

elements& vetor::operator[](int index) const
{
	return elements_[index];
}

void vetor::pushback(elements& element)
{
	if (size_ == capacity_) {
		cout << "Capacidade m�xima do vetor atingida" << endl;
		return;
	}
	elements_[size_] = element;
	size_++;
}

void vetor::pushbackEl(std::string name, int integer)
{
	auto element = new elements(name, integer);
	this->pushback(*element);
}

void vetor::printArray() const
{
	for (int i = 0; i < size_; i++) {
		cout << elements_[i].planet << " => " << elements_[i].stayTime << endl;
	}
}

int vetor::capacity() const
{
	return this->capacity_;
}

void vetor::sort()
{
	auto* aux = new elements[this->capacity()];
	this->mergeSort(aux, 0, this->capacity() - 1);
}

vetor::~vetor()
{
	delete[] this->elements_;
}

void vetor::mergeSort(elements aux[], int esq, int dir)
{
	int meio = (esq + dir) / 2;
	if (esq < dir) {
		mergeSort(aux, esq, meio);
		mergeSort(aux, meio + 1, dir);
		merge(aux, esq, meio, dir);
	}
}

void vetor::merge(elements aux[], int esq, int meio, int dir)
{
	int i, j, k;
	//copia o vetor a ser organizado para o vetor auxiliar.
	for (i = esq; i <= meio; i++) {
		aux[i] = elements_[i];
	}
	//de forma reversa a segunda parte do vetor a ser organizado
	for (j = meio + 1; j <= dir; j++) {
		aux[dir - j + meio + 1] = elements_[j];
	}
	i = esq;
	j = dir;
	for (k = esq; k <= dir; k++) {
		if (aux[i].stayTime <= aux[j].stayTime) {
			elements_[k] = aux[i++];
		}
		else {
			elements_[k] = aux[j--];
		}
	}
}
