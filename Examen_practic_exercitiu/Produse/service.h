#pragma once
#include "repository.h"
#include "validator.h"
#include "observer.h"

class Service: public Observable
{
private:
	Repo& rep;
	Validator& val;
public:

	Service(Repo& rep, Validator& val) : rep{ rep }, val{ val } {};
	//const vector<Produs>& get_lista() const;
	int get_vocale(const Produs& p) const;

	const vector<Produs> get_lista_sort_pret() const;

	void add(int id, string nume, string tip, double pret);

	const Produs& search(int id) const;

	const vector<Produs> get_lista_filtru_pret(double pret) const;
};

