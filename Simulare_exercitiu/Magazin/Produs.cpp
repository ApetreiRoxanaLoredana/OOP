#include "Produs.h"
#include "Exception.h"

int Produs::get_id() const
{
    return id;
}

string Produs::get_description() const
{
    return description;
}

int Produs::get_count() const
{
    return count;
}

double Produs::get_price() const
{
    return price;
}

void Produs::validare() const
{
    string errors = "";
    if (id < 0)
        errors += "Id invalid\n";
    if (count < 0)
        errors += "Numar invalid\n";
    if (price < 0)
        errors += "Pret invalid\n";
    if (errors.size() > 0)
        throw ValidatorException(errors);
}
