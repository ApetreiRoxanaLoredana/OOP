#pragma once
#include <vector>
#include "Repo.h"
#include "Produs.h"
using std::vector;

class Service
{
private:
	Repo& rep;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="rep">Repo</param>
	Service(Repo& rep) : rep{ rep } {};

	/// <summary>
	/// Nu permite copierea servisului;
	/// </summary>
	/// <param name="ot"></param>
	Service(Service& ot) = delete; 

	/// <summary>
	/// Returneaza lista de produse sortata crescator dupa descriere
	/// </summary>
	/// <returns></returns>
	vector<Produs> sortare();

	/// <summary>
	/// Returneaza pretul total al tuturor produselor
	/// </summary>
	/// <returns>double</returns>
	double get_total_price() const;

	/// <summary>
	/// Modifica produsul cu id ul respectiv
	/// Arunca eroare daca nu exita produsul
	/// Arunca eroare daca count nu e valida, count < 0
	/// </summary>
	/// <param name="id">int</param>
	/// <param name="count">int</param>
	void update(int id, int count) const;
};

