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
	//Vetor auxiliar para criacao do vetor dos planetas no mesmo mes de visitacao (capacidade inicial de 10 elementos,
	//mas com o vetor é dinamicamente alocado, ele irá se expandindo de tamanho.)
	auto* aux = new vetor(10, this->numberCharacteres_);
	//Armazena o tempo acumulado em minutos de visitacao
	int accumulatedTime = 0;

	//Contador do mes atual
	int month = 1;

	for (int i = 0; i < planets_->size(); i++) {
		accumulatedTime += (*planets_)[i].stayTime;
		//Ainda da para adicionar planetas no mes atual
		if (accumulatedTime <= this->timePerMonth_) {
			aux->pushback((*planets_)[i]);
		}
		//Esgotou o tempo máximo de visitação para aquele mês.
		else {
			//Organiza o vetor em ordem alfabetica
			aux->sortName();
			//Adiciona o subvetor de planetas a lista e soma 1 ao mes
			planetsVisitation_.addElement(*aux, month++);
			//Cria um novo vetor aux
			aux = new vetor(10, this->numberCharacteres_);
			//Zera o contador de tempo acumulado
			accumulatedTime = 0;
			//Subtrai 1 ao i, pois se entrou no else, o for passou um elemento que nao deveria ter passado.
			i--;
		}
	}
	//Adiciona os elementos do ultimo mês.
	aux->sortName();
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
	this->planets_ = new vetor(numberOfPlanets, this->numberCharacteres_);
}

void planets::addPlanet(std::string planetName, int planetTime)
{
	planets_->pushbackEl(planetName, planetTime);
}
