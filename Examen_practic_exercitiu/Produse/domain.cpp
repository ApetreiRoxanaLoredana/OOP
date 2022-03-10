#include "domain.h"

int Produs::get_id() const
{
    return id;
}

string Produs::get_nume() const
{
    return nume;
}

string Produs::get_tip() const
{
    return tip;
}

double Produs::get_pret() const
{
    return pret;
}

bool Produs::operator==(const Produs& ot) const
{
    return ot.id == id;
}
