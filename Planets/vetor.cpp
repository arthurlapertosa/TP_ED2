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
		cout << "Capacidade máxima do vetor atingida" << endl;
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

void vetor::printArray()
{
	for (int i = 0; i < size_; i++) {
		cout << elements_[i].planet << " => " << elements_[i].stayTime << endl;
	}
}

int vetor::capacity()
{
	return this->capacity_;
}

vetor::~vetor()
{
	delete[] this->elements_;
}
