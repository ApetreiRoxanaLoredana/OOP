#pragma once
#include <string>
using std::string;

class Melodie
{
private:
	int id;
	string titlu;
	string autor;
	int rang;

public:
	Melodie(int id, string titlu, string autor, int rang) : id{ id }, titlu{ titlu }, autor{ autor }, rang{ rang }{};

	int get_id() const;

	string get_titlu() const;

	string get_autor() const;

	int get_rang() const;

	bool operator == (const Melodie& mel) const;
};

