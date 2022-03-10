#include "Validator.h"

void Validator::valideaza(const Joc& j) const
{
	string errors = "";
	if (j.get_id() < 0)
		errors += "Id invalid\n";
	if (j.get_dim() < 3 || j.get_dim() > 5)
		errors += "Dimensiune invalida\n";
	if (j.get_tabla().size() != j.get_dim() * j.get_dim())
		errors += "Tabla invalida\n";
	if (j.get_jucator() != "X" && j.get_jucator() != "O")
		errors += "Jucator invalid\n";
	for(const auto& l: j.get_tabla())
		if (l != 'X' && l != 'O' && l != '-')
		{
			errors += "Tabla invalida\n";
			break;
		}
	if (j.get_stare() != "Neinceput" && j.get_stare() != "In derulare" && j.get_stare() != "Terminat")
		errors += "Stare invalida\n";
	if (errors.size() > 0)
		throw ValidatorException(errors);
}
