#pragma once
#include "Domain.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Repo
{
private:
	string file_name;
	vector<Bicicleta> lista;
public:

	/// <summary>
	/// Construcotr
	/// </summary>
	/// <param name="file_name">string</param>
	Repo(string file_name) : file_name{ file_name } {
		load_from_file();
	};

	/// <summary>
	/// Incarca datele din fisier in lista
	/// </summary>
	void load_from_file();

	/// <summary>
	/// Incarca datele din lista in fisier
	/// </summary>
	void store_to_file();

	/// <summary>
	/// Returneaza lista de biciclete
	/// </summary>
	/// <returns>lista de biciclete</returns>
	const vector<Bicicleta>& get_lista() const;

	/// <summary>
	/// Sterge bicicleta cu id-ul bicicletei b
	/// </summary>
	/// <param name="b">Bicicleta</param>
	void sterge(const Bicicleta& b);
};

