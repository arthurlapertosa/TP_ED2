#include "planets.h"
#include "lista.h"
int main()
{
	planets Teste;
	Teste.fillPlanets();
	Teste.printPlanets();
	Teste.sort();
	cout << endl;
	Teste.printPlanets();

	lista *a = new lista;
	a->addElement(Teste.planetsArray(), 1);
	(*a).addElement(Teste.planetsArray(), 2);
	a->addElement(Teste.planetsArray(), 3);
	a->printL();
	delete a;
}