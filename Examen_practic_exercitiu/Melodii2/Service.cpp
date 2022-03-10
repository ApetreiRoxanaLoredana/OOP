#include "Service.h"

vector<Melodie> Service::get_lista_sort_rank()
{
    vector<Melodie> lista{ rep.get_lista() };
    std::sort(lista.begin(), lista.end(), [](const Melodie& m1, const Melodie& m2) {return m1.get_rank() < m2.get_rank();});
    return lista;
}

void Service::update(int id, string titlu, string artist, int rank)
{
    rep.update(Melodie{ id, titlu, artist, rank });
}

Melodie Service::search(int id)
{
    return rep.search(Melodie{ id, "", "", 0});
}

void Service::remove(int id)
{
    rep.remove(Melodie{ id, "", "", 0 });
}
