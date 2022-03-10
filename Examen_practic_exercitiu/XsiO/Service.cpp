#include "Service.h"

vector<Joc> Service::get_lista_sort_stare()
{
    vector<Joc> lista{ rep.get_all() };
    std::sort(lista.begin(), lista.end(), [](const Joc& j1, const Joc& j2) {return j1.get_stare() < j2.get_stare();});
    return lista;
}

void Service::add(int dim, string tabla, string jucator)
{
    int id;
    val.valideaza(Joc{ 1, dim, tabla, jucator, "Neinceput" });
    while (1)
    {
        try {

            id = rand() % 1000;
            rep.add(Joc{ id, dim, tabla, jucator, "Neinceput" });
            return;
        }
        catch (const std::exception&) {}
    }
}

void Service::update(int id, int dim, string tabla, string jucator, string stare)
{
    val.valideaza(Joc{ id, dim, tabla, jucator, stare });
    rep.update(Joc{ id, dim, tabla, jucator, stare });
}

Joc Service::search(int id)
{
    return rep.search(Joc{ id, 1, "", "", "" });
}


