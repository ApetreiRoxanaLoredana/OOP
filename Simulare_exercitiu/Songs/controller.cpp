#include "controller.h"
#include <vector>
#include <algorithm>

void Controller::update_melodie(int id, string titlu, string autor, int rang)
{
	Melodie mel{ id, titlu, autor, rang };
	val.valideaza(mel);
	rep.update(mel);
}

const vector<Melodie>& Controller::get_lista() const
{
	return rep.get_list();
}

Melodie Controller::search(int id) const
{
	Melodie mel{ id, "ana", "mara", 2 };
	val.valideaza(mel);
	return rep.search(mel);
}

const vector<Melodie> Controller::sorteaza()
{
	vector<Melodie> lista{ rep.get_list() };
	std::sort(lista.begin(), lista.end(), [](const Melodie& mel1, const Melodie& mel2) {return mel1.get_rang() < mel2.get_rang();});
	return lista;
}

void Controller::sterge(const int id)
{
	Melodie mel{ id, "ana", "ana", 2 };
	val.valideaza(mel);
	rep.sterge(mel);
}

vector<int> Controller::ranguri()
{
	vector<int> lista = vector<int>(5, 0);
	const vector<Melodie> lista_mel = rep.get_list();
	for (const auto mel : lista_mel)
		lista[mel.get_rang() - 1]++;

	return lista;
}

