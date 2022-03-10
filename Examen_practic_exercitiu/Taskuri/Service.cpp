#include "Service.h"

vector<Task> Service::get_lista_sort_stare()
{
    vector<Task> lista{ rep.get_lista() };
    std::sort(lista.begin(), lista.end(), [](const Task& t1, const Task& t2) {return t1.get_stare() < t2.get_stare();});
    return lista;
}

void Service::add(int id, string descriere, vector<string> programatori, string stare)
{
    Task t{ id, descriere, programatori, stare };
    val.valideaza(t);
    rep.add(t);
    notify();
}

Task Service::search(int id)
{
    vector<string> l;
    return rep.search(Task{ id, "a", l, "a" });
}

vector<Task> Service::filtru(string programator)
{
    vector<Task> lista;
    for (const auto& t : get_lista_sort_stare())
    {
        for(const auto& p: t.get_programatori())
            if (p == programator)
            {
                lista.push_back(t);
                break;
            }
    }
    return lista;
}

void Service::update(int id, string descriere, vector<string> programatori, string status)
{
    rep.update(Task{ id, descriere, programatori, status });
    notify();
}
