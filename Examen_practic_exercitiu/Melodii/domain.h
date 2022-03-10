#pragma once
#include <string>
using std::string;

class Melodie
{
private:
	int id;
	string titlu;
	string artist;
	string gen;

public:
	Melodie(int id, string titlu, string artist, string gen) : id{ id }, titlu{ titlu }, gen{ gen }, artist{ artist }{};
	
	bool operator == (const Melodie& mel) const {
		return id == mel.id;
	}

	int get_id() const;

	string get_titlu() const;

	string get_artist() const;

	string get_gen() const;

};

