#pragma once
#include "Domain.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Repo
{
private:
	string file_name;
	vector<Cuvant> lista;
	string file_name_istoric;
	vector<string> cuvinte_ghicite;
	int scor;

public:

	Repo(string file_name, string file_name_istoric) : file_name{ file_name }, file_name_istoric{ file_name_istoric } {
		load_from_file();
		scor = 0;
	};

	void load_from_file();

	const vector<Cuvant>& get_lista() const;

	void add_cuvinte(string cuv);

	void reset_istoric(int scor);

	void store_to_file();
};

