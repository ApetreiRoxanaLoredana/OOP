#pragma once
#include "Domain.h"
#include "Repo.h"
#include <string>
#define TElem Apartament
using std::string;

class Validator
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	Validator() = default;

	/// <summary>
	/// Nu permite copierea unui obiect de tipul Validator
	/// </summary>
	/// <param name="ot"></param>
	Validator(const Validator& ot) = delete;

	/// <summary>
	/// Valideaza un obiect de tipul TElem
	/// Arunca ValidatorException daca obiectul nu e conform
	/// </summary>
	/// <param name="a"></param>
	void valideaza(const TElem& a) const;
};

