#include "planets.h"
#include "lista.h"
#include<ctime>
int main()
{
	time_t inicio, final, total;
	time(&inicio);
	planets Teste;
	Teste.fillPlanets();
	//Teste.printPlanets();
	Teste.sort();
	//Teste.printPlanets();
	Teste.buildVisitationList();
	Teste.printList();
	time(&final);
	total = final - inicio;
	std::cout << total << " segundos de execucao" << endl;
}