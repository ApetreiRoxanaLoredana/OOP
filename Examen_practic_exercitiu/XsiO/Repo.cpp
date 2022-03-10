#include "Repo.h"

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw std::exception();

	string line;
	string id_s, dim_s, tabla, jucator, stare;

	while (!fin.eof())
	{
		std::getline(fin, line);
		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue;

		std::istringstream line_stream(line);
		std::getline(line_stream, id_s, ';');
		std::getline(line_stream, dim_s, ';');
		std::getline(line_stream, tabla, ';');
		std::getline(line_stream, jucator, ';');
		std::getline(line_stream, stare);

		int id, dim;
		id = std::stoi(id_s);
		dim = std::stoi(dim_s);

		lista.push_back(Joc{ id, dim, tabla, jucator, stare });
	}
	fin.close();
}

void Repo::store_to_file()
{
	std::ofstream fout(file_name);

	for (const auto& j : lista)
	{
		fout << j.get_id() << ";" << j.get_dim() << ";" << j.get_tabla() << ";";
		fout << j.get_jucator() << ";" << j.get_stare() << "\n";
	}
	fout.close();
}

const vector<Joc>& Repo::get_all() const
{
	return lista;
}

void Repo::add(const Joc& j)
{
	auto it = find(lista.begin(), lista.end(), j);
	if (it != lista.end())
		throw RepoException("Exista acest id\n");
	lista.push_back(j);
	store_to_file();
}

void Repo::update(const Joc& j)
{
	auto it = find(lista.begin(), lista.end(), j);
	if (it != lista.end())
	{
		lista.at(it - lista.begin()) = j;
		store_to_file();
		return;
	}
	throw RepoException("Nu exista acest id\n");
}

Joc Repo::search(const Joc& j)
{
	auto it = find(lista.begin(), lista.end(), j);
	if (it != lista.end())
		return lista.at(it - lista.begin());
	throw RepoException("Nu exista acest id\n");
}
