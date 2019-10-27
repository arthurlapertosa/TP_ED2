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
