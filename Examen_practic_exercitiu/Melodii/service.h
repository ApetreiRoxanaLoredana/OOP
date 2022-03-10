#pragma once
#include <algorithm>
#include "domain.h"
#include "repository.h"

class Service
{
private:
	Repo& rep;

public:
	Service(Repo& rep) : rep{ rep } {};

	Service(const Service& serv) = delete;

	vector<Melodie> get_lista_sort_autor();

	void add(const string titlu, const string artist, const string gen);

	Melodie search(int id);

	void remove(int id);
};

