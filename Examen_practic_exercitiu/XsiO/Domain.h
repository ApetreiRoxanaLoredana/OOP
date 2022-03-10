#pragma once
#include <string>
using std::string;

class Joc
{
private:
	int id;
	int dim;
	string tabla;
	string jucator;
	string stare;
public:
	Joc(int id, int dim, string tabla, string jucator, string stare) : id{ id }, dim{ dim }, tabla{ tabla }, jucator{ jucator }, stare{ stare }{};

	bool operator == (const Joc& j) const;

	int get_id() const;

	int get_dim() const;

	string get_tabla() const;

	string get_jucator() const;

	string get_stare() const;
};

