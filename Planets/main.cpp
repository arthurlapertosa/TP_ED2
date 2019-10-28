#include "planets.h"
#include "lista.h"
int main()
{
	planets Teste;
	Teste.fillPlanets();
	//Teste.printPlanets();
	Teste.sort();
	//Teste.printPlanets();
	Teste.buildVisitationList();
	Teste.printList();
}