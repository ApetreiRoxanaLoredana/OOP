#pragma once
#include "Produs.h"
#include "Exception.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Repo
{
private:
	string file_name;
	vector<Produs> lista;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="file_name">numele fisierului, string</param>
	Repo(string file_name) : file_name{ file_name } {
		load_from_file();
	};

	/// <summary>
	/// Incarca datele din memorie in fisier
	/// </summary>
	void store_to_file();

	/// <summary>
	/// Incarca datele din fisier in memorie
	/// </summary>
	void load_from_file();

	/// <summary>
	/// Adauga un produs in lista
	/// Arunca eroare daca exista deja un produs cu id ul respectiv
	/// </summary>
	/// <param name="p">Produs</param>
	void add(const Produs& p);

	/// <summary>
	/// Modifica produsul care are id-ul respectiv
	/// Arunca eroare daca nu il gaseste
	/// </summary>
	/// <param name="p">Produs</param>
	void update(const Produs& p);

	/// <summary>
	/// Returneaza lista de produse
	/// </summary>
	/// <returns>lista de produse</returns>
	const vector<Produs>& get_list() const;
};

