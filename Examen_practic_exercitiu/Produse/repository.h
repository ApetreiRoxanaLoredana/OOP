#pragma once
#include "domain.h"
#include "exception.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Repo
{
private:
	vector<Produs> lista;
	string file_name;

public:
	Repo(string file_name) : file_name{ file_name } {
		load_from_file();
	};

	void load_from_file();

	void store_to_file();

	const vector<Produs>& get_lista() const;

	void add(const Produs& p);

	const Produs& search(Produs& p) const;
};

