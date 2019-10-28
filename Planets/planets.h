#define _CRT_SECURE_NO_WARNINGS // Para o compilador deixar usar fun��es de C no C++ tive que adicionar isso
#ifndef PLANETS_H
#define PLANETS_H
#include <string>
#include <iostream>
#include "vetor.h"
#include <cstdio>
#include "lista.h"

using std::cout;
using std::endl;

class planets
{
private:
	//Vetor geral de planetas
	vetor* planets_;

	//Tempo gasto por mes por planeta
	int timePerMonth_;

	//Numero de caracteres que o nome dos planetas t�m
	int numberCharacteres_;

	//Lista com os subvetores correspondentes aos meses e os respetivos planetas para visita��o
	lista planetsVisitation_;

public:
	//Inicializa a classe, chamando a fun��o de construir o vetor de planetas
	planets();

	//Adiciona todos os planetas da classe
	void fillPlanets();

	//Printa os planetas
	void printPlanets() const;

	//Organiza em ordem crescente de "StayTime" o vetor de planetas
	void sort();

	//Constr�i a lista de visita��o
	void buildVisitationList();

	//Printa a lista com os meses de visita��o
	void printList();

	//Retorna o vetor de planetas
	vetor& planetsArray();
private:
	//Constroi o vetor de planetas
	void buildPlanets();

	//Adiciona um planeta ao vetor
	void addPlanet(std::string planetName, int planetTime);

};

#endif