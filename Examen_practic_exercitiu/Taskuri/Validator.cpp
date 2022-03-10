#include "Validator.h"
#include "Exception.h"

void Validator::valideaza(const Task& t)
{
	string errors = "";
	if (t.get_id() <= 0)
		errors += "Id invalid\n";
	if (t.get_descriere() == "")
		errors += "Descriere invalida\n";
	string stare = t.get_stare();
	if (t.get_stare() != "open" && t.get_stare() != "inprogress" && t.get_stare() != "closed")
		errors += "Stare invalida\n";
	if (t.get_nr_programatori() < 1 || t.get_nr_programatori() > 4)
		errors += "Programatori invalizi\n";
	if (errors.size() > 0)
		throw ValidatorException(errors);
}

