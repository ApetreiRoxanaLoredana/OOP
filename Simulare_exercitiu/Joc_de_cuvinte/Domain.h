#pragma once
#include <string>
using std::string;

class Cuvant
{
private:
	string cuvant;
	int scor;

public:
	Cuvant(string cuvant, int scor) : cuvant{ cuvant }, scor{ scor }{};

	string get_cuvant() const;

	int get_scor() const;

	Cuvant& operator = (const Cuvant& ot) {
		cuvant = ot.cuvant;
		scor = ot.scor;
		return *this;
	};

};

