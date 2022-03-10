#include "Teste.h"
#include "Domain.h"
#include "Repo.h"
#include "Exception.h"
#include "Validator.h"
#include "Repo_file.h"
#include "Service.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <map>



using namespace std;

void Teste::test_domain()
{
	//constructor
	Apartament a{ 12, "Ana Maria", 34.21, "duplex" };

	//geteri
	assert(a.get_apartament() == 12);
	assert(a.get_nume() == "Ana Maria");
	assert(abs(a.get_suprafata() - 34.21) < 0.000001);
	assert(a.get_tip() == "duplex");

	//seteri
	a.set_apartament(1);
	a.set_nume("Viorica");
	a.set_suprafata(40);
	a.set_tip("garsoniera");

	assert(a.get_apartament() == 1);
	assert(a.get_nume() == "Viorica");
	assert(a.get_suprafata() == 40);
	assert(a.get_tip() == "garsoniera");

	//operatorul ==
	Apartament a2{ 1, "Ana", 89.08, "casa" };
	assert(a == a2);
	//operatorul !=
	Apartament a3{ 2, "Mara", 90, "garsoniera" };
	assert(a != a3);

	//afisarea
	a.print_apartament();
	system("cls");
}

void Teste::test_validator()
{
	Apartament a{ -2, "", -9, "" };
	Validator val{};
	try {
		val.valideaza(a);
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Numarul apartamentului nu e corect\nNumele proprietarului nu poate fi vid\nSuprafata apartamentului nu e corecta\nTipul apartamentului nu poate fi vid\n");
		assert(true);
	}

	Apartament a2{ 2, "Ana", 90.43, "casa" };
	try {
		val.valideaza(a2);
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Tipul apartamentului nu e corect\n");
		assert(true);
	}

	Apartament a3{ 3, "Mara", 98.43, "studio" };
	val.valideaza(a3);
}

void Teste::test_repo()
{
	//get_dim + get_list + add
	Repo repo{};
	assert(repo.get_dim() == 0);
	Apartament a{ 1, "Ana", 32.23, "garsoniera" },
		b{ 2, "Maria", 90.87, "casa" };
	repo.add(a);
	assert(repo.get_dim() == 1);
	repo.add(b);
	assert(repo.get_dim() == 2);

	const VA& list = repo.get_list();
	assert(list.at(0).get_apartament() == 1);
	assert(list.at(0).get_nume() == "Ana");
	assert(abs(list.at(0).get_suprafata() - 32.23) < 0.0000001);
	assert(list.at(0).get_tip() == "garsoniera");
	assert(list.at(1).get_apartament() == 2);
	assert(list.at(1).get_nume() == "Maria");
	assert(abs(list.at(1).get_suprafata() - 90.87) < 0.0000001);
	assert(list.at(1).get_tip() == "casa");

	//add exception
	try {
		repo.add(Apartament{ 1, "", 0, "" });  //introducem apartament deja existent
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Exista deja un apartament cu acest numar\n");
		assert(true);
	}

	//modifica
	Apartament c{ 1, "Cristina", 77.77, "duplex" };
	repo.update(c);
	const VA& list2 = repo.get_list();
	assert(list2.at(0).get_apartament() == 1);
	assert(list2.at(0).get_nume() == "Cristina");
	assert(abs(list2.at(0).get_suprafata() - 77.77) < 0.0000001);
	assert(list2.at(0).get_tip() == "duplex");

	//modifica exception
	try {
		repo.update(Apartament{ 7, "Dan", 98.32, "casa" });
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Nu exista nici un apartament cu acest numar\n");
		assert(true);
	}

	//remove
	assert(repo.get_dim() == 2);
	Apartament d{ 2, "Maria", 88.09, "casa" };
	repo.remove(d); //delete apartament 2
	const VA& list3 = repo.get_list();
	assert(repo.get_dim() == 1);
	assert(list3.at(0).get_apartament() == 1);
	assert(list3.at(0).get_nume() == "Cristina");
	assert(abs(list3.at(0).get_suprafata() - 77.77) < 0.0000001);
	assert(list3.at(0).get_tip() == "duplex");
	repo.remove(a); //delete apartament 1
	assert(repo.get_dim() == 0);

	//remove exception
	try
	{
		repo.remove(Apartament{ 5, "Mara", 9.7, "garsoniera" });
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Nu exista nici un apartament cu acest numar\n");
		assert(true);
	}

	Apartament ap1{ 1, "Ana", 88.99, "duplex" };
	repo.add(ap1);
	Apartament ap2{ 2, "AnaMaria", 33.99, "casa" };
	Apartament ap3{ 3, "Bogdan", 66.7, "garsoniera" };
	repo.add(ap2);
	repo.add(ap3);
	repo.remove(ap1);
	repo.remove(ap2);
	repo.remove(ap3);

	//search
	repo.add(Apartament{ 1, "Ana", 88.99, "duplex" });
	repo.add(Apartament{ 2, "AnaMaria", 33.99, "casa" });
	repo.add(Apartament{ 3, "Bogdan", 66.7, "garsoniera" });

	const Apartament rez = repo.search(Apartament{ 1, "", 0, "" });
	assert(rez.get_apartament() == 1);
	assert(rez.get_nume() == "Ana");
	assert(abs(rez.get_suprafata() - 88.99) < 0.000001);
	assert(rez.get_tip() == "duplex");

	const TElem rez2 = repo.search(Apartament{ 3, "", 0, "" });
	assert(rez2.get_apartament() == 3);
	assert(rez2.get_nume() == "Bogdan");
	assert(abs(rez2.get_suprafata() - 66.7) < 0.000001);
	assert(rez2.get_tip() == "garsoniera");


	//search exception
	try {
		repo.search(Apartament{ 8, "Ana", 98.65, "casa" });
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Nu exista nici un apartament cu acest numar\n");
		assert(true);
	}

}
void Teste::test_serv()
{
	Repo rep{};
	const Validator val{};
	Service serv{ rep, val };

	//add apartament valid
	serv.add_ap(1, "ana", 90.8, "studio");
	assert(rep.get_dim() == 1);
	const VA& list = rep.get_list();
	assert(list.at(0).get_apartament() == 1);
	assert(list.at(0).get_nume() == "ana");
	assert(abs(list.at(0).get_suprafata() - 90.8) < 0.00001);
	assert(list.at(0).get_tip() == "studio");

	//add apartament invalid
	try {
		serv.add_ap(-4, "", -7, "");
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Numarul apartamentului nu e corect\nNumele proprietarului nu poate fi vid\nSuprafata apartamentului nu e corecta\nTipul apartamentului nu poate fi vid\n");
		assert(true);
	}

	//add apartament existent
	try {
		serv.add_ap(1, "mara", 88, "garsoniera");
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Exista deja un apartament cu acest numar\n");
		assert(true);
	}

	//get_list_ap
	const VA& list2 = serv.get_lista_ap();
	assert(list2.size() == 1);
	assert(list2.at(0).get_apartament() == 1);
	assert(list2.at(0).get_nume() == "ana");
	assert(abs(list2.at(0).get_suprafata() - 90.8) < 0.00001);
	assert(list2.at(0).get_tip() == "studio");

	//remove_ap nevalid
	try {
		serv.remove_ap(10);
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Nu exista nici un apartament cu acest numar\n");
		assert(true);
	}

	//remove_ap valid
	serv.remove_ap(1);
	const VA& list3 = serv.get_lista_ap();
	assert(list3.size() == 0);

	//update_ap valid
	serv.add_ap(1, "ana", 23.4, "garsoniera");
	serv.add_ap(2, "mara", 54.3, "studio");

	serv.update_ap(1, "bogdan", 200, "obisnuit");
	const VA& list4 = serv.get_lista_ap();
	assert(list4.size() == 2);
	assert(list4.at(0).get_apartament() == 1);
	assert(list4.at(0).get_nume() == "bogdan");
	assert(abs(list4.at(0).get_suprafata() - 200) < 0.00001);
	assert(list4.at(0).get_tip() == "obisnuit");

	//update_ap nevalid
	try {
		serv.update_ap(1, "", -8, "");
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Numele proprietarului nu poate fi vid\nSuprafata apartamentului nu e corecta\nTipul apartamentului nu poate fi vid\n");
		assert(true);
	}

	//update_ap inexistent
	try {
		serv.update_ap(9, "ana", 77, "camin");
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Nu exista nici un apartament cu acest numar\n");
		assert(true);
	}

	//search_ap valid
	const TElem& a = serv.search_ap(1);
	assert(a.get_apartament() == 1);
	assert(a.get_nume() == "bogdan");
	assert(abs(a.get_suprafata() - 200) < 0.00001);
	assert(a.get_tip() == "obisnuit");

	//search_ap invalid
	try {
		serv.search_ap(-3);
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Numarul apartamentului nu e corect\n");
		assert(true);
	}

	//search_ap inexistent
	try {
		serv.search_ap(10);
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Nu exista nici un apartament cu acest numar\n");
		assert(true);
	}
}

void Teste::test_iteratia2()
{
	Repo rep{};
	Validator val{};
	Service serv{ rep, val };

	//filtru tip valid
	serv.add_ap(1, "ana", 12.32, "studio");
	serv.add_ap(2, "mara", 23.23, "camin");
	serv.add_ap(3, "clara", 10.10, "studio");
	serv.add_ap(4, "mara", 50.9, "studio");

	const VA list = serv.filtru_tip("studio");
	assert(list.at(0).get_apartament() == 1);
	assert(list.at(1).get_apartament() == 3);
	assert(list.at(2).get_apartament() == 4);
	assert(list.at(0).get_tip() == "studio");
	assert(list.at(1).get_tip() == "studio");
	assert(list.at(2).get_tip() == "studio");

	//filtru tip invalid
	try {
		serv.filtru_tip("caca");
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Tipul apartamentului nu e corect\n");
		assert(true);
	}

	//filtru suprafata valida
	const VA list2 = serv.filtru_suprafata(15);
	assert(list2.at(0).get_apartament() == 2);
	assert(list2.at(1).get_apartament() == 4);
	assert(abs(list2.at(0).get_suprafata() - 23.23) < 0.000001);
	assert(abs(list2.at(1).get_suprafata() - 50.9) < 0.000001);

	//filtru suprafata invalida
	try {
		serv.filtru_suprafata(-10);
		assert(false);
	}
	catch (const ValidatorException& ex) {
		assert(ex.get_message() == "Suprafata apartamentului nu e corecta\n");
		assert(true);
	}

	//sortare crescator dupa nume
	const VA list3 = serv.sortare_nume(true);
	assert(list3.size() == 4);
	assert(list3.at(0).get_nume() == "ana");
	assert(list3.at(1).get_nume() == "clara");
	assert(list3.at(2).get_nume() == "mara");
	assert(list3.at(3).get_nume() == "mara");

	//sortare descrescator nume
	const VA list4 = serv.sortare_nume(false);
	assert(list4.at(0).get_nume() == "mara");
	assert(list4.at(1).get_nume() == "mara");
	assert(list4.at(2).get_nume() == "clara");
	assert(list4.at(3).get_nume() == "ana");

	//sortare crescator suprafata
	const VA list5 = serv.sortare_suprafata(true);
	assert(list5.at(0).get_apartament() == 3);
	assert(list5.at(1).get_apartament() == 1);
	assert(list5.at(2).get_apartament() == 2);
	assert(list5.at(3).get_apartament() == 4);

	//sortare descrescator suprafata
	const VA list6 = serv.sortare_suprafata(false);
	assert(list6.at(0).get_apartament() == 4);
	assert(list6.at(1).get_apartament() == 2);
	assert(list6.at(2).get_apartament() == 1);
	assert(list6.at(3).get_apartament() == 3);

	//serv.add_ap(1, "ana", 12.32, "studio");
	//serv.add_ap(2, "mara", 23.23, "camin");
	//serv.add_ap(3, "clara", 10.10, "studio");
	//serv.add_ap(4, "mara", 50.9, "studio");

	//sortare tip descrescator/suprafata crescator
	const VA list7 = serv.sortare_tip_suprafata(false, true);
	assert(list7.at(0).get_apartament() == 3);
	assert(list7.at(1).get_apartament() == 1);
	assert(list7.at(2).get_apartament() == 4);
	assert(list7.at(3).get_apartament() == 2);

	//sortare tip cresc/suprafata descrescator
	const VA list8 = serv.sortare_tip_suprafata(true, false);
	assert(list8.at(0).get_apartament() == 2);
	assert(list8.at(1).get_apartament() == 4);
	assert(list8.at(2).get_apartament() == 1);
	assert(list8.at(3).get_apartament() == 3);

	VA list_t{};
	list_t = list_t;
}

void Teste::test_cos()
{
	Repo rep{};
	Validator val{};
	Service serv{ rep, val };

	//apartamente random din lista
	serv.add_ap(1, "ana", 34, "studio");
	serv.add_ap(2, "maria", 90, "camin");
	serv.add_ap(3, "bogdan", 89, "obisnuit");
	serv.add_ap(4, "mara", 7, "camin");
	serv.add_ap(5, "bogdan", 45, "obisnuit");
	serv.add_ap_existent(1);
	serv.random_ap_existent(4);
	assert(serv.get_dim_cos() == 5);
	const VA& lista = serv.get_cos();
	try {
		rep.search(lista.at(0));
		rep.search(lista.at(1));
		assert(true);
	}
	catch (const RepoException&)
	{
		assert(false);
	}

	try {
		serv.random_ap_existent(4);
		assert(false);
	}
	catch (const ServiceException& ex)
	{
		assert(ex.get_message() == "Nu exista suficiente apartamente in lista\n");
		assert(true);
	}
	serv.remove_ap(1);
	serv.remove_ap(2);
	serv.remove_ap(3);
	serv.remove_ap(4);
	serv.goleste_cos();

	//add apartament existent
	serv.add_ap(1, "ana", 34, "studio");
	serv.add_ap(2, "maria", 90, "camin");

	serv.add_ap_existent(1);
	serv.add_ap_existent(2);
	const VA& list = serv.get_cos();

	assert(list.at(0).get_apartament() == 1);
	assert(list.at(0).get_nume() == "ana");
	assert(list.at(0).get_suprafata() == 34);
	assert(list.at(0).get_tip() == "studio");
	assert(list.at(1).get_apartament() == 2);
	assert(list.at(1).get_nume() == "maria");
	assert(list.at(1).get_suprafata() == 90);
	assert(list.at(1).get_tip() == "camin");

	try {
		serv.add_ap_existent(1);
		assert(false);
	}
	catch (const CosException& ex) {
		assert(ex.get_message() == "Exista deja un apartament cu acest numar\n");
		assert(true);
	}

	//export
	serv.export_list("test");
	ifstream myfile("test.csv");

	string myline;

	getline(myfile, myline);
	assert(myline == "1,ana,34,studio");
	getline(myfile, myline);
	assert(myline == "2,maria,90,camin");

	myfile.close();

	std::map<string, int> my_map = serv.raport();
	assert(my_map["camin"] == 1);
	assert(my_map["studio"] == 1);

	serv.add_ap(9, "mara", 98, "camin");
	my_map = serv.raport();
	assert(my_map["camin"] == 2);

	//goleste lista
	serv.goleste_cos();
	assert(serv.get_dim_cos() == 0);

}

void Teste::test_undo()
{
	Repo rep{};
	Validator val{};
	Service serv{ rep, val };

	//undo add
	serv.add_ap(1, "ana", 44, "obisnuit");
	serv.add_ap(2, "mara", 89, "obisnuit");
	assert(rep.get_dim() == 2);

	serv.undo();
	assert(rep.get_dim() == 1);
	const VA& list = serv.get_lista_ap();
	assert(list.at(0).get_apartament() == 1);
	serv.undo();
	assert(rep.get_dim() == 0);

	//undo remove
	serv.add_ap(1, "ana", 44, "obisnuit");
	serv.add_ap(2, "mara", 89, "obisnuit");
	serv.remove_ap(2);
	serv.remove_ap(1);
	assert(rep.get_dim() == 0);
	serv.undo();
	assert(rep.get_dim() == 1);
	const VA& list2 = serv.get_lista_ap();
	assert(list2.at(0).get_apartament() == 1);
	serv.undo();
	assert(rep.get_dim() == 2);
	const VA& list3 = serv.get_lista_ap();
	assert(list3.at(0).get_apartament() == 1);
	assert(list3.at(1).get_apartament() == 2);

	//undo update
	serv.update_ap(1, "roxana", 99, "studio");
	const VA& list4 = serv.get_lista_ap();
	assert(list4.at(0).get_apartament() == 1);
	assert(list4.at(0).get_nume() == "roxana");
	assert(list4.at(0).get_suprafata() == 99);
	assert(list4.at(0).get_tip() == "studio");

	serv.undo();
	const VA& list5 = serv.get_lista_ap();
	assert(list5.at(0).get_apartament() == 1);
	assert(list5.at(0).get_nume() == "ana");
	assert(list5.at(0).get_suprafata() == 44);
	assert(list5.at(0).get_tip() == "obisnuit");

	//undo add
	serv.undo();
	serv.undo();

	//gata undo
	try {
		serv.undo();
		assert(false);
	}
	catch (const ServiceException& ex) {
		assert(ex.get_message() == "Nu se mai poate face undo\n");
		assert(true);
	}
}

void Teste::test_file()
{
	Repo_file repf{ "test_file.txt" };
	//store to file
	TElem a{ 1, "ana", 77.4, "obisnuit" };
	TElem b{ 2, "mara", 9.87, "studio" };
	repf.add(a);
	repf.add(b);

	ifstream fin("test_file.txt");
	std::string line;
	std::getline(fin, line);
	assert(line == "1;ana;77.4;obisnuit");
	std::getline(fin, line);
	assert(line == "2;mara;9.87;studio");
	fin.close();

	//load from file
	Repo_file repf2{ "test_file.txt" };
	const VA& list = repf2.get_list();
	assert(list.at(0).get_apartament() == 1);
	assert(list.at(0).get_nume() == "ana");
	assert(abs(list.at(0).get_suprafata() - 77.4) < 0.000001);
	assert(list.at(0).get_tip() == "obisnuit");
	assert(list.at(1).get_apartament() == 2);
	assert(list.at(1).get_nume() == "mara");
	assert(abs(list.at(1).get_suprafata() - 9.87) < 0.000001);
	assert(list.at(1).get_tip() == "studio");

	//remove
	repf2.remove(a);
	const VA& list2 = repf2.get_list();
	assert(list2.size() == 1);

	//update
	TElem c{ 2, "oana", 55, "garsoniera" };
	repf2.update(c);
	ifstream fin2("test_file.txt");
	std::getline(fin2, line);
	assert(line == "2;oana;55;garsoniera");
	fin2.close();

	ofstream fout("test_file.txt", std::ios::trunc);
	fout.close();

	//exceptii
	try {
		Repo_file repf3{ "nu_exist.txt" };
		assert(false);
	}
	catch (const RepoException& ex) {
		assert(ex.get_message() == "Error open nu_exist.txt");
		assert(true);
	}
}


void Teste::all_test()
{
	test_domain();
	test_validator();
	test_repo();
	test_serv();
	test_iteratia2();
	test_cos();
	test_undo();
	test_file();
}

