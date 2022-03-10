#include "validator.h"
#include "exception.h"

void Validator::valideaza(const Melodie& mel) const
{
	string errors = "";

	if (mel.get_id() <= 0)
		errors += "Id invalid\n";
	if (mel.get_titlu() == "")
		errors += "Titlul nu poate fi vid\n";
	if (mel.get_autor() == "")
		errors += "Numele autorului nu poate fi vid\n";
	if (mel.get_rang() < 1 || mel.get_rang() > 5)
		errors += "Rangul invalid\n";

	if (errors.size() > 0)
		throw ValidatorException(errors);

}
