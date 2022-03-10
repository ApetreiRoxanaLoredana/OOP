#pragma once
#include <string>
using std::string;

class Coffee
{
private:
	string nume;
	string tara;
	double pret;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="nume">string</param>
	/// <param name="tara">string</param>
	/// <param name="pret">double</param>
	Coffee(string nume, string tara, double pret) : nume{ nume }, tara{ tara }, pret{ pret }{};

	/// <summary>
	/// Returneaza numele cafelei
	/// </summary>
	/// <returns>string</returns>
	string get_nume() const;

	/// <summary>
	/// Returneaza numele tarii de origine a cafelei
	/// </summary>
	/// <returns>string</returns>
	string get_tara() const;

	/// <summary>
	/// Returneaza pretul cafelei
	/// </summary>
	/// <returns>double</returns>
	double get_pret() const;

	/// <summary>
	/// Suprascrie operatorul ==
	/// </summary>
	/// <param name="ot">Coffee</param>
	/// <returns></returns>
	bool operator == (const Coffee& ot) const {
		return nume == ot.nume;
	}
};

