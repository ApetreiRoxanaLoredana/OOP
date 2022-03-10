#pragma once
#include "Domain.h"
#include "MyException.h"
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
	vector<Joc> lista;

public:
	Repo(string file_name) : file_name{ file_name } {
		load_from_file();
	}

	void load_from_file();

	void store_to_file();

	const vector<Joc>& get_all() const;

	void add(const Joc& j);

	void update(const Joc& j);

	Joc search(const Joc& j);


};

