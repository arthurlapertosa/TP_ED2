#include "vetor.h"

vetor::vetor(int capacity, int stringSize)
{
	this->elements_ = new elements[capacity];
	this->size_ = 0;
	this->capacity_ = capacity;
	this->stringsize_ = stringSize;
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
	auto* aux = new elements[this->size()];
	this->mergeSort(aux, 0, this->size() - 1);
	//Deleta o vetor auxiliar depois de dar o sort (ele não é mais necessário)
	delete[] aux;
}

void vetor::sortName()
{
	this->radixSort();
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
			//Para tornar o algoritmo estável, precisou desta última verificação
			if(i <= meio){
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

void vetor::radixSort()
{
	for (int i = 0; i < this->stringsize_; i++) {
		this->countingSortChar(i);
	}
}

void vetor::countingSortChar(int index)
{
	//Cria-se um vetor de 256 elementos, pois um char tem 1 byte, então vai até 256.
	int* vetorCount = new int[256];
	//Inicializa vetor com zeros
	for (int i = 0; i < 256; i++) {
		vetorCount[i] = 0;
	}
	
	for (int i = 0; i < this->size_; i++) {
		vetorCount[(unsigned char)elements_[i].planet[index]]++;
	}
	for (int i = 1; i < 256; i++) {
		vetorCount[i] += vetorCount[i - 1];
	}
	elements* novo = new elements[this->size_];
	elements* antigo = this->elements_;

	for (int i = this->size_ - 1; i >= 0; i--) {
		int novoIndice = --vetorCount[(unsigned char)elements_[i].planet[index]];
		novo[novoIndice] = elements_[i];
	}
	this->elements_ = novo;
	delete[] antigo;
	this->printArray();
}

