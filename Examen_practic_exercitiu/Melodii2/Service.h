#pragma once
#include "Repo.h"
#include <algorithm>

class Service
{
private:
	Repo& rep;
public:
	Service(Repo& rep) : rep{ rep } {};

	Service(const Service& ot) = delete;

	vector<Melodie> get_lista_sort_rank();

	void update(int id, string titlu, string artist, int rank);

	Melodie search(int id);

	void remove(int id);
};

