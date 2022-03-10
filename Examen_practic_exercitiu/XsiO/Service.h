#pragma once
#include "Repo.h"
#include "Validator.h"
#include <algorithm>

class Service
{
private:
	Repo& rep;
	Validator& val;

public:
	Service(Repo& rep, Validator& val) : rep{ rep }, val{ val } {};

	vector<Joc> get_lista_sort_stare();

	void add(int dim, string tabla, string jucator);

	void update(int id, int dim, string tabla, string jucator, string stare);

	Joc search(int id);
};

