#include "teste.h"
#include "domain.h"
#include <assert.h>
#include <fstream>
#include "validator.h"
#include "exception.h"
#include "repository.h"

void Teste::run_all_test()
{
	test_domain();
	test_validator();
	test_repo();
}

void Teste::test_domain()
{
	Melodie mel{ 2, "Buna", "Opra", 3 };
	assert(mel.get_id() == 2);
	assert(mel.get_titlu() == "Buna");
	assert(mel.get_autor() == "Opra");
	assert(mel.get_rang() == 3);
}

void Teste::test_validator()
{
	Melodie mel{ -1, "", "", 0 };
	Validator val;

	try {
		val.valideaza(mel);
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Id invalid\nTitlul nu poate fi vid\nNumele autorului nu poate fi vid\nRangul invalid\n");
		assert(true);
	}
}

void Teste::test_repo()
{
	Repo rep{ "f_test.txt" };
	//store to file

	Melodie mel1{ 2, "cantec1", "maria", 3 };
	Melodie mel2{ 4, "cantec2", "ana", 4 };
	rep.add(mel1);
	rep.add(mel2);

	std::ifstream fin("f_test.txt");
	string line;

	std::getline(fin, line);
	assert(line == "2;cantec1;maria;3");
	std::getline(fin, line);
	assert(line == "4;cantec2;ana;4");

	fin.close();

	//load from file
	Repo rep2{ "f_test.txt" };
	const vector<Melodie> list = rep2.get_list();
	assert(list.size() == 2);

	assert(list[0].get_id() == 2);
	assert(list[0].get_titlu() == "cantec1");
	assert(list[0].get_autor() == "maria");
	assert(list[0].get_rang() == 3);

	assert(list[1].get_id() == 4);
	assert(list[1].get_titlu() == "cantec2");
	assert(list[1].get_autor() == "ana");
	assert(list[1].get_rang() == 4);

	std::ofstream fout("f_test.txt", std::ios::trunc);
	fout.close();
}
