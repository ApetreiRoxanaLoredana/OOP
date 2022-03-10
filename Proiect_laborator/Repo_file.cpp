#include "Repo_file.h"
#include "Exception.h"
#include <fstream>
#include <sstream>

void Repo_file::load_from_file()
{
	std::ifstream fin(file_name);
	if (!fin.is_open())
		throw RepoException("Error open " + file_name);

	std::string line;
	std::string s_apartament, nume, s_suprafata, tip;

	while (!fin.eof())
	{
		std::getline(fin, line);

		if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
			continue; // linie goala

		std::istringstream line_stream(line);
		std::getline(line_stream, s_apartament, ';');
		std::getline(line_stream, nume, ';');
		std::getline(line_stream, s_suprafata, ';');
		std::getline(line_stream, tip, ';');

		const double suprafata = std::stod(s_suprafata);
		const int apartament = std::stoi(s_apartament);

		const TElem ap{ apartament, nume, suprafata, tip };
		Repo::add(ap);
	}
	fin.close();

}

void Repo_file::store_to_file()
{
	std::ofstream fout(file_name);

	for (const auto& ap : Repo::get_list())
	{
		fout << ap.get_apartament() << ";" << ap.get_nume() << ";";
		fout << ap.get_suprafata() << ";" << ap.get_tip() << '\n';
	}
	fout.close();
}

void Repo_file::add(const TElem& a)
{
	Repo::add(a);
	store_to_file();
}

void Repo_file::update(const TElem& a)
{
	Repo::update(a);
	store_to_file();
}

void Repo_file::remove(const TElem& a)
{
	Repo::remove(a);
	store_to_file();
}
