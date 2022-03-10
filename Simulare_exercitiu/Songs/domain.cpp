#include "domain.h"

int Melodie::get_id() const
{
    return id;
}

string Melodie::get_titlu() const
{
    return titlu;
}

string Melodie::get_autor() const
{
    return autor;
}

int Melodie::get_rang() const
{
    return rang;
}

bool Melodie::operator==(const Melodie& mel) const
{
    return mel.id == id;
}


