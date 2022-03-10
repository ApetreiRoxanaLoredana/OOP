#include "service.h"

vector<Melodie> Service::get_lista_sort_autor()
{
    vector<Melodie> list{ rep.get_lista() };
    std::sort(list.begin(), list.end(), [](const Melodie& m1, const Melodie& m2) {return m1.get_artist() < m2.get_artist();});
    return list;
}

void Service::add(const string titlu, const string artist, const string gen)
{
    const vector<Melodie>& lista{ rep.get_lista() };
    auto it = lista.begin();
    int id = 0;
    while (it != lista.end())
    {
        id = rand() % 1000;
        Melodie mel{ id, titlu, artist, gen };
        it = find(lista.begin(), lista.end(), mel);
    }
    rep.add(Melodie{ id, titlu, artist, gen });

}

Melodie Service::search(int id)
{
    Melodie mel{ id, "a", "b", "c" };
    return rep.search(mel);
}

void Service::remove(int id)
{
    rep.remove(Melodie{ id, "a", "b", "c" });
}
