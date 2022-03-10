#include "Teste.h"
#include "domain.h"
#include "repository.h"
#include "service.h"
#include <assert.h>
#include <vector>
#include <string>
#include <fstream>
using std::vector;
using std::string;

void Teste::test_domain()
{
	Melodie mel{ 1, "ana", "mara", "pop"};
	assert(mel.get_id() == 1);
	assert(mel.get_titlu() == "ana");
	assert(mel.get_artist() == "mara");
	assert(mel.get_gen() == "pop");

	Melodie m2{ 1, "a", "b", "c" };
	assert(mel == m2);
}

void Teste::test_repo()
{
	//add
	Repo rep{ "fisi_test.txt" };
	rep.add(Melodie{ 1, "ana", "mara", "pop" });
	auto list1 = rep.get_lista();
	assert(list1.at(0).get_id() == 1);
	assert(list1.at(0).get_titlu() == "ana");
	assert(list1.at(0).get_artist() == "mara");
	assert(list1.at(0).get_gen() == "pop");

	//load from file
	Repo rep2{ "fisi_test.txt" };
	auto list2 = rep2.get_lista();
	assert(list2.size() == 1);
	assert(list2.at(0).get_id() == 1);
	assert(list2.at(0).get_titlu() == "ana");
	assert(list2.at(0).get_artist() == "mara");
	assert(list2.at(0).get_gen() == "pop");

	//store to file
	rep.add(Melodie{ 2, "cantec", "eu", "rock" });
	std::fstream fin("fisi_test.txt");
	string line;
	std::getline(fin, line);
	assert(line == "1;ana;mara;pop");
	std::getline(fin, line);
	assert(line == "2;cantec;eu;rock");
	fin.close();

	//search
	auto mel2 = rep.search(Melodie{ 1, "", "", "" });
	assert(mel2.get_id() == 1);
	assert(mel2.get_titlu() == "ana");
	assert(mel2.get_artist() == "mara");
	assert(mel2.get_gen() == "pop");

	//remove
	rep.remove(Melodie{ 1, "", "", "" });
	auto list3 = rep.get_lista();
	assert(list3.size() == 1);
	rep.remove(Melodie{ 2, "", "", "" });
	list3 = rep.get_lista();
	assert(list3.size() == 0);

	//exceptii
	try {
		Repo rep3{ "nu exist" };
		assert(false);
	}
	catch (const std::exception&)
	{
		assert(true);
	}

	try {
		rep.search(Melodie{ 109, "", "", "" });
		assert(false);
	}
	catch (const std::exception&) {
		assert(true);
	}

	try {
		rep.remove(Melodie{ 109, "", "", "" });
		assert(false);
	}
	catch (const std::exception&) {
		assert(true);
	}

	std::ofstream fout("fisi_test.txt", std::ios::trunc);
	fout.close();
}

void Teste::test_serv()
{
	Repo rep{ "fisi_test.txt" };
	Service serv{ rep };

	//seach
	rep.add(Melodie{ 1, "ana", "oana", "rock" });
	auto mel = serv.search(1);
	assert(mel.get_id() == 1);
	assert(mel.get_titlu() == "ana");
	assert(mel.get_artist() == "oana");
	assert(mel.get_gen() == "rock");

	//remove
	serv.remove(1);
	auto list1 = serv.get_lista_sort_autor();
	assert(list1.size() == 0);

	//add
	serv.add("ceva", "mara", "pop");
	auto list2 = serv.get_lista_sort_autor();
	assert(list2.size() == 1);
	assert(list2.at(0).get_titlu() == "ceva");
	assert(list2.at(0).get_artist() == "mara");
	assert(list2.at(0).get_gen() == "pop");

	//sort
	serv.add("altceva", "ana", "disco");
	auto list3 = serv.get_lista_sort_autor();
	assert(list3.size() == 2);
	assert(list3.at(0).get_titlu() == "altceva");
	assert(list3.at(0).get_artist() == "ana");
	assert(list3.at(0).get_gen() == "disco");

	assert(list3.at(1).get_titlu() == "ceva");
	assert(list3.at(1).get_artist() == "mara");
	assert(list3.at(1).get_gen() == "pop");

	std::ofstream fout("fisi_test.txt", std::ios::trunc);
	fout.close();
}

void Teste::run_all()
{
	test_domain();
	test_repo();
	test_serv();
}
