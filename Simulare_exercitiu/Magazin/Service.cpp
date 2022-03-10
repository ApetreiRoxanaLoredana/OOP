#include "Service.h"
#include <algorithm>

vector<Produs> Service::sortare()
{
    vector<Produs> lista{ rep.get_list() };
    std::sort(lista.begin(), lista.end(), [](const Produs& p1, const Produs& p2) {return p1.get_description() < p2.get_description();});
    return lista;
}

double Service::get_total_price() const
{
    const vector<Produs> lista{ rep.get_list() };
    double price = 0;
    for (const auto& p : lista)
        price += (p.get_price() * p.get_count());
    return price;
}

void Service::update(int id, int count) const
{
    Produs p{ id, "ceva", count, 20 };
    p.validare();
    rep.update(p);
}



