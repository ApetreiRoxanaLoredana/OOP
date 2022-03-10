#pragma once
#include <string>
using std::string;

class Melodie
{
private:
	int id;
	string titlu;
	string artist;
	int rank;
public:
	Melodie(int id, string titlu, string artist, int rank) : id{ id }, titlu{ titlu }, artist{ artist }, rank{ rank }{};

	bool operator == (const Melodie& ot) const;

	int get_id() const;

	int get_rank() const;

	string get_titlu() const;

	string get_artist() const;

};

