#include "service.h"
#include <algorithm>



int Service::get_vocale(const Produs& p) const
{
    string nume = p.get_nume();
    int cnt = 0;
    for (const auto& litera : nume)
    {
        if (litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u')
            cnt++;
        if (litera == 'A' || litera == 'E' || litera == 'I' || litera == 'O' || litera == 'U')
            cnt++;
    }
    return cnt;
}

const vector<Produs> Service::get_lista_sort_pret() const
{
    vector<Produs> list{ rep.get_lista() };
    std::sort(list.begin(), list.end(), [](const Produs& p1, const Produs& p2) {return p1.get_pret() < p2.get_pret();});
    return list;
}

void Service::add(int id, string nume, string tip, double pret)
{
    Produs p{ id, nume, tip, pret };
    val.valideaza(p);
    rep.add(p);
    notify();
}

const Produs& Service::search(int id) const
{
    Produs p{ id, "n", "s", 3 };
    return rep.search(p);
}

const vector<Produs> Service::get_lista_filtru_pret(double pret) const
{
    vector<Produs> lista;
    for (const auto& p : rep.get_lista())
        if (p.get_pret() <= pret)
            lista.push_back(p);
    return lista;
}
