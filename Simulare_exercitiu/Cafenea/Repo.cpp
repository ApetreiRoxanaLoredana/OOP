#include "Repo.h"
#include <fstream>
#include <sstream>
#include <exception>

void Repo::load_from_file()
{
	std::ifstream fin(file_name);

	if (!fin.is_open())
		throw std::exception("Fisierul nu a putut fi deschis");

	string line;
	string nume, tara, s_pret;

	while (!fin.eof())
	{
		std::getline(fin, line);
		std::istringstream stream_line(line);

		std::getline(stream_line, nume, ',');
		std::getline(stream_line, tara, ',');
		std::getline(stream_line, s_pret);

		double pret = std::stod(s_pret);
		Coffee cof{ nume, tara, pret };
		lista.push_back(cof);
	}

	fin.close();
}

const vector<Coffee>& Repo::get_lista()
{
	return lista;
}

Coffee Repo::search(const Coffee& cof)
{
	auto it = find(lista.begin(), lista.end(), cof);
	if (it != lista.end())
		return lista.at(it - lista.begin());
	throw std::exception("Nu s-a gasit");
}
