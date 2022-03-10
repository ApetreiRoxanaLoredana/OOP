#pragma once
#include <vector>
#include "Domain.h"
#include "Repo.h"
#include <string>
#include "Observer.h"

class Cos
{
private:

	std::vector<TElem> cos;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <returns></returns>
	Cos() noexcept {};

	/// <summary>
	/// Adauga un element nou in cos
	/// </summary>
	/// <param name="ap">Obiect de tipul TElem</param>
	void add(const TElem& ap);

	void remove(const TElem& ap);

	/// <summary>
	/// Returneaza dimensiune cosului
	/// </summary>
	/// <returns>int</returns>
	int get_dim() const noexcept;

	/// <summary>
	/// Sterge toate elementele din cos
	/// </summary>
	/// <returns></returns>
	void goleste() noexcept;

	/// <summary>
	/// Exporta elementele din cos intr-un fisier 
	/// </summary>
	/// <param name="file_name"></param>
	void export_csv(string file_name) const;

	/// <summary>
	/// Returneaza un vecotr care contine elementele din cos
	/// </summary>
	/// <returns></returns>
	const std::vector<TElem>& get_cos() const noexcept;


};

