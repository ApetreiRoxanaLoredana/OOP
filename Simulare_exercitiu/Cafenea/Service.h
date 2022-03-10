#pragma once
#include "Repo.h"

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
	/// Nu permite copierea obiectului
	/// </summary>
	/// <param name="ot"></param>
	Service(const Service& ot) = delete;

	/// <summary>
	/// Filtreaza lista de cafele dupa tara si pretul cafelei
	/// </summary>
	/// <param name="tara">string</param>
	/// <param name="pret">double</param>
	/// <returns>lista filtrata</returns>
	vector<Coffee> filtrare(string tara, double pret);

	/// <summary>
	/// Sorteaza crescator lista dupa tara si descrescator in cadrul tarii dupa pret
	/// </summary>
	/// <returns>lista sortata</returns>
	vector<Coffee> sortare();

	/// <summary>
	/// Returneaza lista de cafele
	/// </summary>
	/// <returns>lista de cafele</returns>
	const vector<Coffee>& get_lista() const;

	/// <summary>
	/// Cuauta o cafea dupa numele ei
	/// </summary>
	/// <param name="nume">string</param>
	/// <returns>Coffee</returns>
	Coffee search(string nume);
};

