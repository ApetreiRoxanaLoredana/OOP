#include "repository.h"

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw std::exception();

	string line;
	string id_s, titlul, artist, gen;

	while (!fin.eof())
	{
		std::getline(fin, line);
		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue;
		std::istringstream line_stream(line);
		std::getline(line_stream, id_s, ';');
		std::getline(line_stream, titlul, ';');
		std::getline(line_stream, artist, ';');
		std::getline(line_stream, gen);

		int id = std::stoi(id_s);
		Melodie mel{ id, titlul, artist, gen };
		lista.push_back(mel);
	}
	fin.close();
}

void Repo::stoare_to_file()
{
	std::ofstream fout(file_name);
	for (const auto& mel : lista)
	{
		fout << mel.get_id() << ";" << mel.get_titlu() << ";";
		fout << mel.get_artist() << ";" << mel.get_gen() << "\n";
	}
	fout.close();
}

const vector<Melodie>& Repo::get_lista() const
{
	return lista;
}

void Repo::add(const Melodie& mel)
{
	lista.push_back(mel);
	stoare_to_file();
}

const Melodie Repo::search(const Melodie& mel) const
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
		stoare_to_file();
		return;
	}
	throw std::exception();
}
