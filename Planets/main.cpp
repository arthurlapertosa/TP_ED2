#include "planets.h"

int main()
{
	planets Teste;
	Teste.fillPlanets();
	Teste.printPlanets();
	Teste.sort();
	cout << endl;
	Teste.printPlanets();
}