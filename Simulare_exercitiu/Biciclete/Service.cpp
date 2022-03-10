#include "Service.h"
#include <algorithm>

void Service::sterge_tip(string tip)
{
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (const auto& b : rep.get_lista())
			if (b.get_tip() == tip)
			{
				rep.sterge(b);
				ok = true;
			}
	}
}

void Service::sterge_max()
{
	double maxim = -1;
	for (const auto& b : rep.get_lista())
		maxim = std::max(maxim, b.get_pret());

	bool ok = true;
	while (ok)
	{
		ok = false;
		for (const auto& b : rep.get_lista())
			if (b.get_pret() == maxim)
			{
				rep.sterge(b);
				ok = true;
			}
	}
}

vector<Bicicleta> Service::sorteaza()
{
	vector<Bicicleta> lista{ rep.get_lista() };
	std::sort(lista.begin(), lista.end(), [](const Bicicleta& b1, const Bicicleta& b2) {return b1.get_tip() < b2.get_tip();});
	return lista;
}
