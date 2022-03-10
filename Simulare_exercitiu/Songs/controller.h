#pragma once
#include "repository.h"
#include "validator.h"
#include <map>

class Controller
{
private:
	Repo& rep;
	const Validator& val;

public:
	Controller(Repo& rep, const Validator& val) :rep{ rep }, val{ val }{};

	Controller(const Controller& ot) = delete;

	void update_melodie(int id, string titlu, string autor, int rang);

	const vector<Melodie>& get_lista() const;

	Melodie search(int id) const;

	const vector<Melodie> sorteaza();

	void sterge(const int id);

	vector<int> ranguri();
};

