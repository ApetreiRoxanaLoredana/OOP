#include "Service.h"
#include <algorithm>

vector<Coffee> Service::filtrare(string tara, double pret)
{
	const vector<Coffee>& lista{ rep.get_lista() };
	vector<Coffee> lista_f;

	for (const auto& cof : lista)
		if (cof.get_tara() == tara && cof.get_pret() < pret)
			lista_f.push_back(cof);
	return lista_f;
}

vector<Coffee> Service::sortare()
{
	vector<Coffee> lista{ rep.get_lista() };
	std::sort(lista.begin(), lista.end(), [](const Coffee& c1, const Coffee& c2) {return c1.get_tara() < c2.get_tara();});
	std::sort(lista.begin(), lista.end(), [](const Coffee& c1, const Coffee& c2) {return c1.get_pret() > c2.get_pret();});
	return lista;
}

const vector<Coffee>& Service::get_lista() const
{
	return rep.get_lista();
}

Coffee Service::search(string nume)
{
	Coffee cof{ nume, "", 0 };
	return rep.search(cof);
}
