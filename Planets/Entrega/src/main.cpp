#include "planets.h"
#include "lista.h"
int main()
{
	planets Planetas;
	Planetas.fillPlanets();
	Planetas.sort();
	Planetas.buildVisitationList();
	Planetas.printList();
}