#include "Repo.h"
#include <fstream>
#include <sstream>

void Repo::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw std::exception("invalid");

	string line;
	string s_id, tip, s_pret;

	while (!fin.eof())
	{
		std::getline(fin, line);

		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue;

		std::istringstream stream_line(line);

		std::getline(stream_line, s_id, ',');
		std::getline(stream_line, tip, ',');
		std::getline(stream_line, s_pret, ',');

		int id = std::stoi(s_id);
		double pret = std::stod(s_pret);

		Bicicleta b{ id, tip, pret };
		lista.push_back(b);
	}

	fin.close();
}

void Repo::store_to_file()
{
	std::ofstream fout(file_name);

	for (const auto& b : get_lista())
		fout << b.get_id() << "," << b.get_tip() << "," << b.get_pret() << "\n";
	fout.close();
}

const vector<Bicicleta>& Repo::get_lista() const
{
	return lista;
}

void Repo::sterge(const Bicicleta& b)
{
	auto it = find(lista.begin(), lista.end(), b);
	if (it != lista.end())
	{
		lista.erase(it);
		store_to_file();
		return;}}
