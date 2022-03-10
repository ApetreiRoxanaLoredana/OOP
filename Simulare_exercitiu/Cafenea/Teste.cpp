#include "Teste.h"
#include "Domain.h"
#include "Repo.h"
#include "Service.h"
#include <assert.h>
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;

void Teste::run_all_test()
{
	domain_test();
	repo_test();
	serv_test();
}

void Teste::domain_test()
{
	Coffee c{ "latte", "italia", 45 };
	assert(c.get_nume() == "latte");
	assert(c.get_tara() == "italia");
	assert(abs(c.get_pret() - 45) < 0.00001);

	Coffee c2{ "latte", "spania", 23 };
	assert(c == c2);
}

void Teste::repo_test()
{
	std::ofstream fout("fisi_test.txt");
	fout << "latte,romania,3.2" << '\n';
	fout << "cafea,italia,7.9\n";
	fout.close();

	Repo rep{ "fisi_test.txt" };
	const vector<Coffee> list{ rep.get_lista() };
	assert(list[0].get_nume() == "latte");
	assert(list[0].get_tara() == "romania");
	assert(abs(list[0].get_pret() - 3.2) < 0.00001);

	assert(list[1].get_nume() == "cafea");
	assert(list[1].get_tara() == "italia");
	assert(abs(list[1].get_pret() - 7.9) < 0.00001);

	auto c3 = rep.search(Coffee{ "latte", "", 8 });
	assert(c3.get_nume() == "latte");
	assert(c3.get_tara() == "romania");
	assert(abs(c3.get_pret() - 3.2) < 0.00001);

	try {
		rep.search(Coffee{ "mo", "", 9 });
		assert(false);
	}
	catch (std::exception ex)
	{
		assert(true);
	}

	try {
		Repo rep2{ "nu_exist_deloc" };
		assert(false);
	}
	catch (std::exception ex)
	{
		assert(true);
	}

	std::ofstream fout2("fisi_test.txt", std::ios::trunc);
	fout2.close();


}

void Teste::serv_test()
{
	std::ofstream fout("fisi_test.txt");
	fout << "latte,romania,3.2\n";
	fout << "cafea,italia,7.9\n";
	fout << "cafea2,italia,8.6";
	fout.close();

	Repo rep{ "fisi_test.txt" };
	Service serv{ rep };

	vector<Coffee> list0{ serv.get_lista() };
	assert(list0.size() == 3);

	vector<Coffee> list{ serv.filtrare("italia", 8) };

	assert(list[0].get_nume() == "cafea");
	assert(list[0].get_tara() == "italia");
	assert(abs(list[0].get_pret() - 7.9) < 0.00001);

	vector<Coffee> list2{ serv.sortare() };
	assert(list2[0].get_nume() == "cafea2");
	assert(list2[0].get_tara() == "italia");
	assert(abs(list2[0].get_pret() - 8.6) < 0.00001);

	assert(list2[1].get_nume() == "cafea");
	assert(list2[1].get_tara() == "italia");
	assert(abs(list2[1].get_pret() - 7.9) < 0.00001);

	assert(list2[2].get_nume() == "latte");
	assert(list2[2].get_tara() == "romania");
	assert(abs(list2[2].get_pret() - 3.2) < 0.00001);

	auto c = serv.search("latte");
	assert(c.get_nume() == "latte");
	assert(c.get_tara() == "romania");
	assert(abs(c.get_pret() - 3.2) < 0.00001);

	std::ofstream fout3("fisi_test.txt", std::ios::trunc);
	fout3.close();
}
