#include "Repo.h"
#include <fstream>
#include <sstream>
#include <exception>

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw std::exception("Fisierul nu a putut fi deschis\n");

	string line;
	string cuvant, s_scor;

	while (!fin.eof())
	{
		std::getline(fin, line);
		std::istringstream stream_line(line);

		std::getline(stream_line, cuvant, ';');
		std::getline(stream_line, s_scor);

		int scor_f = std::stoi(s_scor);

		Cuvant cuv{ cuvant, scor_f };
		lista.push_back(cuv);
	}

	fin.close();
}

const vector<Cuvant>& Repo::get_lista() const
{
	return lista;
}

void Repo::add_cuvinte(string cuv)
{
	cuvinte_ghicite.push_back(cuv);
}


void Repo::reset_istoric(int scor_u)
{
	this->scor = scor_u;
	store_to_file();
	cuvinte_ghicite.clear();
	this->scor = 0;
}

void Repo::store_to_file()
{
	std::ofstream fout(file_name_istoric);

	fout << scor << '\n';
	for (const auto& cuv : cuvinte_ghicite)
		fout << cuv << '\n';

	fout.close();
}


