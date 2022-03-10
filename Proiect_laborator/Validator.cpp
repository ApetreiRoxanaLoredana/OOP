#include "Validator.h"
#include "Exception.h"
#include "Domain.h"
#include <string>
using namespace std;


void Validator::valideaza(const TElem& a) const
{
	string errors;

	if (a.get_apartament() <= 0)
		errors.append("Numarul apartamentului nu e corect\n");
	if (a.get_nume() == "")
		errors.append("Numele proprietarului nu poate fi vid\n");
	if (a.get_suprafata() <= 0)
		errors.append("Suprafata apartamentului nu e corecta\n");
	if (a.get_tip() == "")
		errors.append("Tipul apartamentului nu poate fi vid\n");
	else
		//tip = studio/garsoniera/camin/obisnuit
		if (a.get_tip() != "studio" && a.get_tip() != "garsoniera" && a.get_tip() != "camin" && a.get_tip() != "obisnuit")
			errors.append("Tipul apartamentului nu e corect\n");

	if (errors.size() != 0)
		throw ValidatorException(errors);
}
