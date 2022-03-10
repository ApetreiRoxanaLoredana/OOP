#pragma once
#include "domain.h"
#include "exception.h"
#include <string>
#include <vector>
#include <fstream>
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
	};

	Repo(const Repo& ot) = delete;

	void add(const Melodie& mel);

	const vector<Melodie>& get_list() const;

	void load_from_file();

	void store_to_file();

	void update(const Melodie& mel);

	Melodie search(const Melodie& mel);

	void sterge(const Melodie& mel);
};

