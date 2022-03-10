#include "Domain.h"

bool Joc::operator==(const Joc& j) const
{
    return id == j.id;
}

int Joc::get_id() const
{
    return id;
}

int Joc::get_dim() const
{
    return dim;
}

string Joc::get_tabla() const
{
    return tabla;
}

string Joc::get_jucator() const
{
    return jucator;
}

string Joc::get_stare() const
{
    return stare;
}
