#include "planets.h"

planets::planets()
{
	this->buildPlanets();
}

void planets::fillPlanets()
{
	int time;
	char* name = new char[this->numberCharacteres_];
	for (int i = 0; i < this->planets_->capacity(); i++) {
		scanf("%d %s", &time, name);
		this->addPlanet(name, time);
	}
}

void planets::printPlanets() const
{
	this->planets_->printArray();
}

void planets::sort()
{
	planets_->sort();
}

void planets::buildVisitationList()
{
	//Vetor auxiliar para cria��o do vetor dos planetas no mesmo m�s de visita��o
	auto* aux = new vetor(10);
	//Armazena o tempo acumulado em minutos de visita��o
	int accumulatedTime = 0;

	//Contador do m�s atual
	int month = 1;

	for (int i = 0; i < planets_->size(); i++) {
		accumulatedTime += (*planets_)[i].stayTime;
		//Ainda d� para adicionar planetas no m�s atual
		if (accumulatedTime <= this->timePerMonth_) {
			aux->pushback((*planets_)[i]);
		}
		//Tempo daquele m�s se esgotou
		else {
			//Adiciona o subvetor de planetas � lista e soma 1 ao m�s
			planetsVisitation_.addElement(*aux, month++);
			//Cria um novo vetor aux
			aux = new vetor(10);
			//Zera o contador de tempo acumulado
			accumulatedTime = 0;
			//Subtrai 1 ao i, pois se entrou no else, o for passou um elemento que n�o deveria ter passado.
			i--;
		}
	}
	planetsVisitation_.addElement(*aux, month);
}

void planets::printList()
{
	this->planetsVisitation_.printL();
}

vetor& planets::planetsArray()
{
	return *planets_;
}

void planets::buildPlanets()
{
	int time, numberOfPlanets, numberOfCharacteres;
	scanf("%d %d %d", &time, &numberOfPlanets, &numberOfCharacteres);
	this->timePerMonth_ = time;
	this->numberCharacteres_ = numberOfCharacteres;
	this->planets_ = new vetor(numberOfPlanets);
}

void planets::addPlanet(std::string planetName, int planetTime)
{
	planets_->pushbackEl(planetName, planetTime);
}
