#include "validator.h"
#include "exception.h"

void Validator::valideaza(const Produs& p)
{
	string erori = "";
	if (p.get_id() < 0)
		erori += "Id-ul nu poate fi negativ\n";
	if (p.get_nume() == "")
		erori += "Numele nu poate fi vid\n";
	if (p.get_pret() < 1 || p.get_pret() > 100)
		erori += "Pret invalid\n";

	if (erori.size() > 0)
		throw ValidatorException(erori);
}
