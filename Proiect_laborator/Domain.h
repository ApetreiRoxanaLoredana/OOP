#pragma once
#include <iostream>
#include <string>
using std::string;

class Apartament
{
private:
	int apartament;
	string nume_proprietar;
	double suprafata;
	string tip;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="apartament">numarul apartamentului (int)</param>
	/// <param name="nume_proprietar">numele proprietarului (string)</param>
	/// <param name="suprafata">suprafata apartamentului (float)</param>
	/// <param name="tip">tipul apartamentului (string)</param>
	Apartament(int apartament, string nume_proprietar, double suprafata, string tip)
		: apartament{ apartament }, nume_proprietar{ nume_proprietar }, suprafata{ suprafata }, tip{ tip }{
	}

	Apartament() = default;

	Apartament(const Apartament& a) : apartament{ a.apartament }, nume_proprietar{ a.nume_proprietar }, suprafata{ a.suprafata }, tip{ a.tip }
	{
		std::cout << "copie" << "\n";
	}

	/// <summary>
	/// Returneaza numarul apartamentului
	/// </summary>
	/// <returns>int</returns>
	int get_apartament() const noexcept;

	/// <summary>
	/// Returneaza numele proprietarului
	/// </summary>
	/// <returns>string</returns>
	string get_nume() const;

	/// <summary>
	/// Returneaza suprafata apartamentului
	/// </summary>
	/// <returns></returns>
	double get_suprafata() const noexcept;

	/// <summary>
	/// Returneaza tipul apartamentului
	/// </summary>
	/// <returns>string</returns>
	string get_tip() const;

	/// <summary>
	/// Seteaza numarul apartamentului cu o alta valoare
	/// </summary>
	/// <param name="other">numarul unui apartament (int)</param>
	void set_apartament(const int other) noexcept;

	/// <summary>
	/// Seteaza numele proprietarului cu o alta valoare
	/// </summary>
	/// <param name="other"></param>
	void set_nume(const string other);

	/// <summary>
	/// Seteaza suprafata apartamentului cu o alta valoare
	/// </summary>
	/// <param name="other">suprafata (float)</param>
	void set_suprafata(const double other) noexcept;

	/// <summary>
	/// Seteaza tipul apartamentului cu o alta valoare
	/// </summary>
	/// <param name="other">tip apartament (string)</param>
	void set_tip(const string other);

	/// <summary>
	/// Afiseaza un apartament
	/// </summary>
	void print_apartament() const;

	/// <summary>
	/// Defineste operatorul ==
	/// </summary>
	/// <param name="a1">un obiect de tipul Apartament</param>
	/// <returns>True/False</returns>
	bool operator==(const Apartament& a1) const noexcept;

	/// <summary>
	/// Defineste opetratorul !=
	/// </summary>
	/// <param name="a">un obiect de tipul Apartament</param>
	/// <returns>True/False</returns>
	bool operator!=(const Apartament& a) const noexcept;

	/// <summary>
	/// Defineste operatorul =
	/// </summary>
	/// <param name="ot">obiect de tipul Apartament</param>
	/// <returns>none</returns>
	Apartament& operator = (const Apartament& ot);


};

