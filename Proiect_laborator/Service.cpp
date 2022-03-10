#include "Service.h"
#include "Service.h"
#include "Exception.h"
#include "UndoAdauga.h"
#include "UndoSterge.h"
#include "UndoModifica.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

void Service::add_ap(const int numar, const string nume, const double suprafata, const string tip)
{
	TElem a{ numar, nume, suprafata, tip };
	val.valideaza(a);
	repo.add(a);
	undo_actions.push_back(std::make_unique<UndoAdauga>(repo, a));
}

const VA& Service::get_lista_ap() const
{
	return repo.get_list();
}

void Service::remove_ap(const int numar)
{
	TElem a{ numar, "a", 1, "studio" }; //creeam un apartament valid
	val.valideaza(a);
	a = repo.search(a);
	repo.remove(a);
	try {
		cos.remove(a);
		notify();
	}
	catch (const CosException) {};
	
	undo_actions.push_back(std::make_unique<UndoSterge>(repo, a));
}

void Service::update_ap(const int numar, const string nume, const double suprafata, const string tip)
{
	TElem a{ numar, nume, suprafata, tip };
	val.valideaza(a);
	TElem a_list = repo.search(a);
	repo.update(a);
	notify();
	undo_actions.push_back(std::make_unique<UndoModifica>(repo, a_list));
}

const TElem Service::search_ap(const int numar) const
{
	TElem a{ numar, "a", 1, "studio" };
	val.valideaza(a);
	return repo.search(a);
}

const VA Service::filtru_tip(const string tip)
{
	TElem a{ 1, "a", 1, tip };
	val.valideaza(a);

	const VA& lista = repo.get_list();

	VA lista_noua(lista.size());
	auto it = copy_if(lista.begin(), lista.end(), lista_noua.begin(), [tip](const TElem& e) {return e.get_tip() == tip;});
	lista_noua.resize(it - lista_noua.begin());

	return lista_noua;
}

const VA Service::filtru_suprafata(const double suprafata)
{
	TElem a{ 1, "a", suprafata, "studio" };
	val.valideaza(a);
	const VA& lista = repo.get_list();

	VA lista_noua(lista.size());
	auto it = copy_if(lista.begin(), lista.end(), lista_noua.begin(), [suprafata](const TElem& e) noexcept {return e.get_suprafata() > suprafata;});
	lista_noua.resize(it - lista_noua.begin());

	return lista_noua;
}

const VA Service::sortare_nume(bool reverse)
{
	VA list{ repo.get_list() };
	std::sort(list.begin(), list.end(), [](const TElem& e1, const TElem& e2) {return e1.get_nume() < e2.get_nume();});
	if (!reverse)
		std::reverse(list.begin(), list.end());
	return list;
}

const VA Service::sortare_suprafata(bool reverse)
{
	VA list{ repo.get_list() };
	std::sort(list.begin(), list.end(), [](const TElem& e1, const TElem& e2) noexcept {return e1.get_suprafata() < e2.get_suprafata();});
	if (!reverse)
		std::reverse(list.begin(), list.end());
	return list;
}

const VA Service::sortare_tip_suprafata(bool reverse1, bool reverse2)
{
	VA list{ repo.get_list() };

	std::sort(list.begin(), list.end(), [](const TElem& e1, const TElem& e2) noexcept {return e1.get_suprafata() < e2.get_suprafata();});
	if (!reverse2)
		std::reverse(list.begin(), list.end());

	if (!reverse1)
		std::sort(list.begin(), list.end(), [](const TElem& e1, const TElem& e2) {return e1.get_tip() > e2.get_tip();});
	else
		std::sort(list.begin(), list.end(), [](const TElem& e1, const TElem& e2) {return e1.get_tip() < e2.get_tip();});
	return list;
}

void Service::goleste_cos() noexcept
{
	cos.goleste();
	notify();
}


void Service::random_ap_existent(const int nr)
{
	int nr_ap = repo.get_dim() - cos.get_dim();
	if (nr_ap < nr)
		throw ServiceException("Nu exista suficiente apartamente in lista\n");
	nr_ap = nr;
	const VA& list{ repo.get_list() };
	while (nr_ap)
	{
		const int numar = rand() % repo.get_dim();
		TElem ap = repo.search(list.at(numar));
		try
		{
			cos.add(ap);
			nr_ap--;
		}
		catch (CosException&)
		{
			continue;
		}
	}

	notify();
}

void Service::add_ap_existent(int nr_ap)
{
	TElem rez = search_ap(nr_ap);
	cos.add(rez);
	notify();
}

void Service::remove_cos(int nr_ap)
{
	TElem rez = search_ap(nr_ap);
	cos.remove(rez);
	notify();
}

void Service::export_list(string file_name)
{
	file_name += ".csv";
	cos.export_csv(file_name);
}

const std::map<string, int> Service::raport()
{
	std::map<string, int> my_d;

	const VA& list = repo.get_list();
	for (const auto& e : list)
	{
		if (my_d.find(e.get_tip()) != my_d.end())
			my_d[e.get_tip()]++;
		else
			my_d.emplace(e.get_tip(), 1);
	}


	return my_d;
}

int Service::get_dim_cos() const noexcept
{
	return cos.get_dim();
}

const std::vector<TElem>& Service::get_cos() const noexcept
{
	return cos.get_cos();
}

void Service::undo()
{
	if (undo_actions.empty())
		throw ServiceException("Nu se mai poate face undo\n");
	undo_actions.back()->doUndo();
	undo_actions.pop_back();
	notify();
}


