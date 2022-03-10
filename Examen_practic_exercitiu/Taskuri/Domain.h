#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;

class Task
{
private:
	int id;
	string descriere;
	vector<string> programatori;
	string stare;

public:
	Task(int id, string descriere, vector<string> programatori, string stare) : id{ id }, descriere{ descriere }, programatori{ programatori }, stare{ stare }{};

	bool operator ==(const Task& ot) const;

	int get_id() const;

	string get_descriere() const;

	vector<string> get_programatori() const;

	int get_nr_programatori() const;

	string get_stare() const;

};

