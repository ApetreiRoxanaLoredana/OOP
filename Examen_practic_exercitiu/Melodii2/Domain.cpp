#include "Domain.h"

bool Melodie::operator==(const Melodie& ot) const
{
    return id == ot.id;
}

int Melodie::get_id() const
{
    return id;
}

int Melodie::get_rank() const
{
    return rank;
}

string Melodie::get_titlu() const
{
    return titlu;
}

string Melodie::get_artist() const
{
    return artist;
}

