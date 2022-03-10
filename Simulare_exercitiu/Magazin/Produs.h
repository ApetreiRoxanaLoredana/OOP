#pragma once
#include <string>
using std::string;

class Produs
{
private:
	int id;
	string description;
	int count;
	double price;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="id">int</param>
	/// <param name="description">string</param>
	/// <param name="count">int</param>
	/// <param name="price">double</param>
	Produs(int id, string description, int count, double price) : id{ id }, description{ description }, count{ count }, price{ price }{};

	/// <summary>
	/// Suprascrie operatorul ==
	/// </summary>
	/// <param name="ot">Produs</param>
	/// <returns>true/false</returns>
	bool operator == (const Produs& ot) const {
		return id == ot.id;
	}

	/// <summary>
	/// Returneaza id-ul produsului
	/// </summary>
	/// <returns>int</returns>
	int get_id() const;

	/// <summary>
	/// Returneaza descrierea
	/// </summary>
	/// <returns>string</returns>
	string get_description() const;

	/// <summary>
	/// Returneaza numarul de produse
	/// </summary>
	/// <returns>int</returns>
	int get_count() const;

	/// <summary>
	/// Returneaza pretul produsului
	/// </summary>
	/// <returns>double</returns>
	double get_price() const;

	/// <summary>
	/// Valideaza produsul
	/// Arunca eroare daca nu e conform
	/// </summary>
	void validare() const;
};