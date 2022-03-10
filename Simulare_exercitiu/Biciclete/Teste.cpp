#include "Teste.h"
#include "Domain.h"
#include "Repo.h"
#include "Service.h"
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
using std::vector;
using std::string;

void Teste::run_all_test()
{
	domain_test();
	repo_test();
	serv_test();
}

void Teste::domain_test()
{
	Bicicleta b1{ 1, "bmx", 23.3 };
	assert(b1.get_id() == 1);
	assert(b1.get_tip() == "bmx");
	assert(abs(b1.get_pret() - 23.3) < 0.000001);

	Bicicleta b2{ 1, "bmxdsfsd", 78 };
	assert(b1 == b2);
}

void Teste::repo_test()
{
	std::ofstream fout("test.txt");
	fout << "1,bmx,23.3\n";
	fout << "2,road,34.5\n";
	fout.close();

	Repo rep{ "test.txt" };

	//load 
	const vector<Bicicleta>& list{ rep.get_lista() };
	assert(list.size() == 2);
	assert(list.at(0).get_id() == 1);
	assert(list.at(0).get_tip() == "bmx");
	assert(abs(list.at(0).get_pret() - 23.3) < 0.00001);

	assert(list.at(1).get_id() == 2);
	assert(list.at(1).get_tip() == "road");
	assert(abs(list.at(1).get_pret() - 34.5) < 0.00001);

	//store / sterge
	rep.sterge(Bicicleta{ 1, "ana", 43 });

	Repo rep2{ "test.txt" };
	const vector<Bicicleta>& list2{ rep2.get_lista() };
	assert(list2.size() == 1);
	assert(list2.at(0).get_id() == 2);
	assert(list2.at(0).get_tip() == "road");
	assert(abs(list2.at(0).get_pret() - 34.5) < 0.00001);

	std::ofstream fout2("test.txt", std::ios::trunc);
	fout2.close();

	try {
		Repo rep3{ "nu_exist.txt" };
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}

}

void Teste::serv_test()
{
	std::ofstream fout("test.txt");
	fout << "2,road,34.5\n";
	fout << "1,bmx,23.3\n";

	fout.close();

	Repo rep{ "test.txt" };
	Service serv{ rep };

	const vector<Bicicleta>& list1{ serv.sorteaza() };
	assert(list1.size() == 2);
	assert(list1.at(0).get_id() == 1);
	assert(list1.at(0).get_tip() == "bmx");
	assert(abs(list1.at(0).get_pret() - 23.3) < 0.00001);

	assert(list1.at(1).get_id() == 2);
	assert(list1.at(1).get_tip() == "road");
	assert(abs(list1.at(1).get_pret() - 34.5) < 0.00001);

	serv.sterge_max();
	const vector<Bicicleta>& list2{ serv.sorteaza() };
	assert(list2.size() == 1);
	assert(list2.at(0).get_id() == 1);
	assert(list2.at(0).get_tip() == "bmx");
	assert(abs(list2.at(0).get_pret() - 23.3) < 0.00001);

	serv.sterge_tip("bmx");
	const vector<Bicicleta>& list3{ serv.sorteaza() };
	assert(list3.size() == 0);

	std::ofstream fout2("test.txt", std::ios::trunc);
	fout2.close();
}
