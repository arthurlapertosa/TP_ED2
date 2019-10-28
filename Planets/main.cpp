#include "planets.h"
#include "lista.h"
int main()
{
	planets Teste;
	Teste.fillPlanets();
	Teste.sort();
	Teste.buildVisitationList();
	Teste.printList();
}