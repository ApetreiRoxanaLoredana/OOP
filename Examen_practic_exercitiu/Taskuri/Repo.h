#pragma once
#include "Domain.h"
#include "Exception.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using std::vector;
using std::string;

class Repo
{
private:
	string file_name;
	vector<Task> lista;

public:
	Repo(string file_name) : file_name(file_name) {
		load_from_file();
	}

	void load_from_file();

	void store_to_file();

	const vector<Task>& get_lista() const;

	void add(const Task& t);

	Task search(const Task& t);

	void update(const Task& t);
};

