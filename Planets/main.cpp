#include"vetor.h"

int main()
{
	auto novo = new vetor(10);
	novo->pushbackEl("Arthur", 22);
	novo->pushbackEl("Saraah", 99);
	novo->pushbackEl("Saraah", 99);
	novo->printArray();
}