#include "Repo.h"
#include <fstream>
#include <sstream>

void Repo::store_to_file()
{
	std::ofstream fout(file_name);

	for (const auto& p : Repo::get_list())
	{
		fout << p.get_id() << ";" << p.get_description() << ";";
		fout << p.get_count() << ";" << p.get_price() << "\n";
	}

	fout.close();
}

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw RepoException("Fisierul nu a putu fi deschis");

	string line;
	string s_id, description, s_count, s_price;

	while (!fin.eof())
	{
		std::getline(fin, line);
		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue; // linie goala
		std::istringstream stream_line(line);

		std::getline(stream_line, s_id, ';');
		std::getline(stream_line, description, ';');
		std::getline(stream_line, s_count, ';');
		std::getline(stream_line, s_price);

		int id = std::stoi(s_id);
		int count = std::stoi(s_count);
		double price = std::stod(s_price);

		Produs p{ id, description, count, price };
		add(p);
	}

	fin.close();
}

void Repo::add(const Produs& p)
{
	auto it = find(lista.begin(), lista.end(), p);
	if (it != lista.end())
		throw RepoException("Exista deja un produs cu acest id\n");
	lista.push_back(p);
	store_to_file();
}

void Repo::update(const Produs& p)
{
	auto it = find(lista.begin(), lista.end(), p);
	if (it != lista.end())
	{
		Produs p2{ p.get_id(), lista.at(it - lista.begin()).get_description(), p.get_count(), lista.at(it - lista.begin()).get_price() };
		lista.at(it - lista.begin()) = p2;
		store_to_file();
		return;
	}
	throw RepoException("Nu exista un produs cu acest id\n");
}

const vector<Produs>& Repo::get_list() const
{
	return lista;
}
