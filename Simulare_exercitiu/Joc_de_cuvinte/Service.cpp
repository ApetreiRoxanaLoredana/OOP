#include "Service.h"
#include <random>
#include <stdlib.h>

Cuvant Service::get_cuv_random() const
{
    const vector<Cuvant> list{ rep.get_lista() };
    int dim = (int)list.size();

    int poz = rand() % dim;

    return list.at(poz);
}

const vector<Cuvant>& Service::get_lista() const
{
    return rep.get_lista();
}

void Service::add_cuv(string cuv)
{
    rep.add_cuvinte(cuv);
}

void Service::reset(int scor)
{
    rep.reset_istoric(scor);
}
