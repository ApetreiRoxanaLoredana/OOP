#pragma once
#include "Domain.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using std::string;
using std::vector;

class Repo
{
private:
	string file_name;
	vector<Melodie> lista;
public:
	Repo(string file_name) : file_name{ file_name } {
		load_from_file();
	}

	void load_from_file();

	void store_to_file();

	const vector<Melodie>& get_lista() const;

	void update(const Melodie& mel);

	Melodie search(const Melodie& mel);

	void remove(const Melodie& mel);
};

