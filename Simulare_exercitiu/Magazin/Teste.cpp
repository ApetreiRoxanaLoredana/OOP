#include "Teste.h"
#include "Produs.h"
#include "Exception.h"
#include "Repo.h"
#include "Service.h"
#include <assert.h>
#include <fstream>

void Teste::run_all_test()
{
	domain_test();
	repo_test();
	serv_test();
}

void Teste::domain_test()
{
	Produs p{ 2, "lapte", 7, 34.2 };
	assert(p.get_id() == 2);
	assert(p.get_description() == "lapte");
	assert(p.get_count() == 7);
	assert(abs(p.get_price() - 34.2) < 0.00001);

	Produs p2{ -3, "miere", -3, -2 };
	try {
		p2.validare();
		assert(false);
	}
	catch (const ValidatorException& ex)
	{
		assert(ex.get_message() == "Id invalid\nNumar invalid\nPret invalid\n");
		assert(true);
	}

	Produs p3{ 2, "ana", 7, 9 };

	assert(p3 == p);
}

void Teste::repo_test()
{
	//store to file
	Repo rep{"fisi_test.txt"}; //fisierul e gol
	Produs p1{ 1, "lapte", 3, 4.5 };
	Produs p2{ 2, "miere", 4, 5.5 };
	rep.add(p1);
	rep.add(p2);

	std::ifstream fin("fisi_test.txt");
	string line;

	std::getline(fin, line);
	assert(line == "1;lapte;3;4.5");
	std::getline(fin, line);
	assert(line == "2;miere;4;5.5");
	fin.close();

	//load from file
	Repo rep2{ "fisi_test.txt" };
	const vector<Produs>lista{ rep2.get_list() };
	assert(lista[0].get_id() == 1);
	assert(lista[0].get_description() == "lapte");
	assert(lista[0].get_count() == 3);
	assert(abs(lista[0].get_price() - 4.5) < 0.000001);

	assert(lista[1].get_id() == 2);
	assert(lista[1].get_description() == "miere");
	assert(lista[1].get_count() == 4);
	assert(abs(lista[1].get_price() - 5.5) < 0.000001);

	//update
	Produs p3{ 1, "cocos", 6, 8 };
	rep.update(p3);
	const vector<Produs> lista2{ rep.get_list() };
	assert(lista2[0].get_id() == 1);
	assert(lista2[0].get_description() == "lapte");
	assert(lista2[0].get_count() == 6);
	assert(abs(lista2[0].get_price() - 4.5) < 0.000001);

	//exceptii
	Produs p4{ 1, "ana", 3, 8 };
	try {
		rep.add(p4);
		assert(false);
	}
	catch (const RepoException& ex)
	{
		assert(ex.get_message() == "Exista deja un produs cu acest id\n");
		assert(true);
	}

	Produs p5{ 9, "ana", 3, 8 };
	try {
		rep.update(p5);
		assert(false);
	}
	catch (const RepoException& ex)
	{
		assert(ex.get_message() == "Nu exista un produs cu acest id\n");
		assert(true);
	}

	std::ofstream fout("fisi_test.txt", std::ios::trunc);
	fout.close();

}

void Teste::serv_test()
{
	Repo rep{ "fisi_test.txt" };
	Service serv{ rep };

	Produs p1{ 1, "lapte", 3, 4.5 };
	Produs p2{ 2, "miere", 4, 5.5 };
	rep.add(p2);
	rep.add(p1);

	const vector<Produs> list{ serv.sortare() };
	assert(list[0].get_id() == 1);
	assert(list[0].get_description() == "lapte");
	assert(list[0].get_count() == 3);
	assert(abs(list[0].get_price() - 4.5) < 0.000001);

	assert(list[1].get_id() == 2);
	assert(list[1].get_description() == "miere");
	assert(list[1].get_count() == 4);
	assert(abs(list[1].get_price() - 5.5) < 0.000001);

	auto price = serv.get_total_price(); // 13.5 + 22 = 35.5
	assert(abs(price - 35.5) < 0.000001);

	serv.update(1, 10);
	const vector<Produs> list2{ serv.sortare() };
	assert(list2[0].get_id() == 1);
	assert(list2[0].get_description() == "lapte");
	assert(list2[0].get_count() == 10);
	assert(abs(list2[0].get_price() - 4.5) < 0.000001);

	std::ofstream fout("fisi_test.txt", std::ios::trunc);
	fout.close();
}
