#include "repository.h"
#include <sstream>

void Repo::add(const Melodie& mel)
{
	auto rez = find(lista.begin(), lista.end(), mel);
	if (rez != lista.end())
		throw RepoException("Exista deja o melodie cu acest id\n");

	lista.push_back(mel);
	store_to_file();
}

const vector<Melodie>& Repo::get_list() const
{
	return lista;
}

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw RepoException("Fisierul nu a putut fi deschis\n");

	string line;
	string s_id, titlu, autor, s_rang;

	while (!fin.eof())
	{
		std::getline(fin, line);
		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue; // linie goala

		std::istringstream line_stream(line);
		std::getline(line_stream, s_id, ';');
		std::getline(line_stream, titlu, ';');
		std::getline(line_stream, autor, ';');
		std::getline(line_stream, s_rang, ';');

		const int id = std::stoi(s_id);
		const int rang = std::stoi(s_rang);

		const Melodie mel{ id, titlu, autor, rang };
		add(mel);
	}
	fin.close();
}

void Repo::store_to_file()
{
	std::ofstream fout(file_name);

	for (const auto& mel : get_list())
	{
		fout << mel.get_id() << ";" << mel.get_titlu() << ";";
		fout << mel.get_autor() << ";" << mel.get_rang() << "\n";
	}

	fout.close();
}

void Repo::update(const Melodie& mel)
{
	auto it = find(lista.begin(), lista.end(), mel);
	if (it != lista.end())
	{
		lista.at(it - lista.begin()) = mel;
		store_to_file();
		return;
	}

	throw RepoException("Nu exista nici o melodie cu acest id\n");
}

Melodie Repo::search(const Melodie& mel)
{
	auto it = find(lista.begin(), lista.end(), mel);
	if (it != lista.end())
		return lista.at(it - lista.begin());
	throw RepoException("Nu exista nici o melodie cu acest id\n");
}

void Repo::sterge(const Melodie& mel)
{
	auto it = find(lista.begin(), lista.end(), mel);
	if (it != lista.end())
	{
		lista.erase(it);
		store_to_file();
		return;
	}
	throw RepoException("Nu exista nici o melodie cu acest id\n");
}
