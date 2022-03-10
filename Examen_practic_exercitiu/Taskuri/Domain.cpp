#include "Domain.h"

bool Task::operator==(const Task& ot) const
{
    return id == ot.id;
}

int Task::get_id() const
{
    return id;
}

string Task::get_descriere() const
{
    return descriere;
}

vector<string> Task::get_programatori() const
{
    return programatori;
}

int Task::get_nr_programatori() const
{
    return (int)programatori.size();
}

string Task::get_stare() const
{
    return stare;
}
