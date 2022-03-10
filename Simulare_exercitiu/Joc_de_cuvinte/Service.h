#pragma once
#include "Repo.h"
#include "Domain.h"

class Service
{
private:
	Repo& rep;

public:
	Service(Repo& rep) : rep{ rep } {};

	Service(const Service& ot) = delete;

	Cuvant get_cuv_random() const;

	const vector<Cuvant>& get_lista() const;

	void add_cuv(string cuv);

	void reset(int scor);
};

