#pragma once
#include "Domain.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Repo
{
private:
	vector<Coffee> lista;
	string file_name;

public:

	/// <summary>
	/// Construcotr
	/// </summary>
	/// <param name="file_name">string</param>
	Repo(string file_name) : file_name{ file_name } {
		load_from_file();
	};

	/// <summary>
	/// Incarca elemetele din fisier in memorie
	/// </summary>
	void load_from_file();

	/// <summary>
	/// Returneaza lista de cafele
	/// </summary>
	/// <returns>lista de cafele</returns>
	const vector<Coffee>& get_lista();

	/// <summary>
	/// Cauta o cafea dupa numele ei
	/// Arunca exceptie daca nu o gaseste
	/// </summary>
	/// <param name="cof">Coffee</param>
	/// <returns>Coffee</returns>
	Coffee search(const Coffee& cof);
};

