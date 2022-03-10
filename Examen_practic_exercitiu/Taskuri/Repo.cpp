#include "Repo.h"

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw std::exception();

	string line;
	string id_s, descriere, programator, stare;
	vector<string> programatori;

	while (!fin.eof())
	{
		std::getline(fin, line);

		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue;

		std::istringstream line_stream(line);
		std::getline(line_stream, id_s, ';');
		std::getline(line_stream, descriere, ';');

		programatori.clear();
		while (!line_stream.eof())
		{
			std::getline(line_stream, programator, ';');
			programatori.push_back(programator);
		}
		
		stare = programatori.back();
		programatori.pop_back();

		int id = std::stoi(id_s);

		Task t{ id, descriere, programatori, stare };
		lista.push_back(t);
	}
	fin.close();
}

void Repo::store_to_file()
{
	std::ofstream fout(file_name);
	for (const auto& t : lista)
	{
		fout << t.get_id() << ";" << t.get_descriere() << ";";
		for (const auto& p : t.get_programatori())
			fout << p << ";";
		fout << t.get_stare() << "\n";
	}
	fout.close();
}

const vector<Task>& Repo::get_lista() const
{
	return lista;
}

void Repo::add(const Task& t)
{
	auto it = find(lista.begin(), lista.end(), t);
	if (it != lista.end())
		throw RepoException("Exista deja acest id\n");
	lista.push_back(t);
	store_to_file();
}

Task Repo::search(const Task& t)
{
	auto it = find(lista.begin(), lista.end(), t);
	if (it != lista.end())
		return lista.at(it - lista.begin());
	throw std::exception();
}

void Repo::update(const Task& t)
{
	auto it = find(lista.begin(), lista.end(), t);
	if (it != lista.end())
	{
		lista.at(it - lista.begin()) = t;
		store_to_file();
		return;
	}
	throw std::exception();
}
