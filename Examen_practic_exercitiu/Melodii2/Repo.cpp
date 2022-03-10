#include "Repo.h"

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw std::exception();

	string line;
	string id_s, titlu, artist, rank_s;

	while (!fin.eof())
	{
		std::getline(fin, line);

		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue;

		std::istringstream line_stream(line);
		std::getline(line_stream, id_s, ';');
		std::getline(line_stream, titlu, ';');
		std::getline(line_stream, artist, ';');
		std::getline(line_stream, rank_s);

		int id = std::stoi(id_s);
		int rank = std::stoi(rank_s);

		Melodie mel{ id, titlu, artist, rank };
		lista.push_back(mel);
	}
	fin.close();
}

void Repo::store_to_file()
{
	std::ofstream fout(file_name);

	for (const auto& m : lista)
	{
		fout << m.get_id() << ";" << m.get_titlu() << ";";
		fout << m.get_artist() << ";" << m.get_rank() << "\n";
	}
	fout.close();
}

const vector<Melodie>& Repo::get_lista() const
{
	return lista;
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
	throw std::exception();
}

Melodie Repo::search(const Melodie& mel)
{
	auto it = find(lista.begin(), lista.end(), mel);
	if (it != lista.end())
		return lista.at(it - lista.begin());
	throw std::exception();
}

void Repo::remove(const Melodie& mel)
{
	auto it = find(lista.begin(), lista.end(), mel);
	if (it != lista.end())
	{
		lista.erase(it);
		store_to_file();
		return;
	}
	throw std::exception();
}
