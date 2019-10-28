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
		capacity_ *= 2;
		auto* novo = new elements[capacity_];
		for (int i = 0; i < size_; i++) {
			novo[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = novo;
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
		cout << elements_[i].planet << " " << elements_[i].stayTime << endl;
	}
}

void vetor::printArray(int mes) const
{
	for (int i = 0; i < size_; i++) {
		cout << mes << " " << elements_[i].planet << " " << elements_[i].stayTime << endl;
	}
}

int vetor::capacity() const
{
	return this->capacity_;
}

int vetor::size() const
{
	return this->size_;
}

void vetor::sort()
{
	int i, j;
	elements aux;
	for (i = 1; i < size(); i++) {
		aux = elements_[i];
		j = i - 1;
		while (j >= 0 && (aux.stayTime < elements_[j].stayTime)) {
			elements_[j + 1] = elements_[j];
			j--;
		}
		elements_[j + 1] = aux;
	}
}

void vetor::sortName()
{
	auto* aux = new elements[this->size()];
	this->mergeSortName(aux, 0, this->size() - 1);
	//Deleta o vetor auxiliar depois de dar o sort (ele não é mais necessário)
	delete[] aux;
}

vetor::~vetor()
{
	delete[] this->elements_;
}

void vetor::troca(elements& a, elements& b)
{
	elements aux = a;
	a = b;
	b = aux;
}

void vetor::mergeSortName(elements aux[], int esq, int dir)
{
	int meio = (esq + dir) / 2;
	if (esq < dir) {
		mergeSortName(aux, esq, meio);
		mergeSortName(aux, meio + 1, dir);
		mergeName(aux, esq, meio, dir);
	}
}

void vetor::mergeName(elements aux[], int esq, int meio, int dir)
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
		if (aux[i].planet <= aux[j].planet) {
			//Para tornar o algoritmo estável, precisou desta última verificação
			if (i <= meio) {
				elements_[k] = aux[i++];
			}
			else {
				elements_[k] = aux[j--];
			}
		}
		else {
			elements_[k] = aux[j--];
		}
	}
}
