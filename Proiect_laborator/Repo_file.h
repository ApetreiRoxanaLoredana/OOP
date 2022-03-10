#pragma once
#include "Repo.h"
#include <string>

class Repo_file : public Repo
{
private:

	const std::string file_name; //numele fisierului

	/// <summary>
	/// Incarca elementele din fisier in lista
	/// </summary>
	void load_from_file();

	/// <summary>
	/// Incarca elementele din lista in fisier
	/// </summary>
	void store_to_file();

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="f_name">numele fisierului (string)</param>
	Repo_file(const std::string f_name) :Repo{}, file_name{ f_name }{
		load_from_file(); // incarcam datele din fisier
	};

	/// <summary>
	/// Adauga un element nou in lista
	/// Arunca RepoException daca exista deja elementul in lista
	/// Salveaza elementele din lista in fisier
	/// </summary>
	/// <param name="a"></param>
	void add(const TElem& a) override;

	/// <summary>
	/// Modifica un element din lista
	/// Arunca RepoExceptie daca nu exista elementul respectiv in lista
	/// Salveaza elementele din lista in fisier
	/// </summary>
	/// <param name="a"></param>
	void update(const TElem& a) override;

	/// <summary>
	/// Sterge elementul din lista
	/// Arunca RepoException daca nu gaseste elementul in lista
	/// Salveaza eleementele din lista in fisier
	/// </summary>
	/// <param name="a"></param>
	void remove(const TElem& a) override;
};

