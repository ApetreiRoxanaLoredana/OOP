#pragma once
#include <algorithm>
#include "Repo.h"
#include "Validator.h"
#include "Observer.h"

class Service: public Observable
{
private:
	Repo& rep;
	Validator& val;

public:
	Service(Repo& rep, Validator& val) : rep{ rep }, val{ val } {};

	Service(const Service& ot) = delete;

	vector<Task> get_lista_sort_stare();

	void add(int id, string descriere, vector<string> programatori, string stare);

	Task search(int id);

	vector<Task> filtru(string programator);

	void update(int id, string descriere, vector<string> programatori, string status);
};

