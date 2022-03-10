#pragma once
#include "Domain.h"
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
	/// <param name="ot">Service</param>
	Service(const Service& ot) = delete;

	/// <summary>
	/// Sterge toate bicicletele de tipul respectiv
	/// </summary>
	/// <param name="tip"></param>
	void sterge_tip(string tip);

	/// <summary>
	/// Sterge toate bicicletele cu suma maxima
	/// </summary>
	void sterge_max();

	/// <summary>
	/// Returneaza lista de biciclete sortata crescator dupa tipul acestora
	/// </summary>
	/// <returns>lista de biciclete sortata</returns>
	vector<Bicicleta> sorteaza();
};

