#pragma once
#include <string>
using std::string;

class  Produs
{

private:
	int id;
	string nume;
	string tip;
	double pret;

public:

	Produs(int id, string nume, string tip, double pret) : id{ id }, nume{ nume }, tip{ tip }, pret{ pret }{};

	int get_id() const;
	string get_nume() const;
	string get_tip() const;
	double get_pret() const;
	bool operator ==(const Produs& ot) const;
};

