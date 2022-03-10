#pragma once
#include <string>
using std::string;

class Bicicleta
{
private:
	int id;
	string tip;
	double pret;
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="id">int</param>
	/// <param name="tip">string</param>
	/// <param name="pret">double</param>
	Bicicleta(int id, string tip, double pret) : id{ id }, tip{ tip }, pret{ pret }{};

	/// <summary>
	/// Returneaza id ul
	/// </summary>
	/// <returns>int</returns>
	int get_id() const;

	/// <summary>
	/// Returneaza tipul bicicletei
	/// </summary>
	/// <returns>string</returns>
	string get_tip() const;

	/// <summary>
	/// Returneaza pretul bicicletei
	/// </summary>
	/// <returns>double</returns>
	double get_pret() const;

	/// <summary>
	/// Suprascrie operatorul ==
	/// </summary>
	/// <param name="ot">Bicicleta</param>
	/// <returns>true/false</returns>
	bool operator == (const Bicicleta& ot) const {
		return id == ot.id;
	}
};

