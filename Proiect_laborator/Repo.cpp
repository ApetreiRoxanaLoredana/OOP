#include "Repo.h"
#include "Exception.h"
#include <algorithm>
#include <iostream>
using namespace std;

const VA& Repo::get_list() noexcept
{
    return list;
}

int Repo::get_dim() const noexcept
{
    return (int)list.size();
}

void Repo::add(const TElem& a)
{
    auto rez = find(list.begin(), list.end(), a);
    if (rez != list.end())
        throw RepoException("Exista deja un apartament cu acest numar\n");

    list.push_back(a);
}

void Repo::update(const TElem& a)
{
    auto rez = find(list.begin(), list.end(), a);
    if (rez != list.end())
    {
        list.at(rez - list.begin()) = a;
        return;
    }

    throw RepoException("Nu exista nici un apartament cu acest numar\n");
}

void Repo::remove(const TElem& a)
{
    auto rez = find(list.begin(), list.end(), a);
    if (rez != list.end())
    {
        list.erase(rez);
        return;
    }

    throw RepoException("Nu exista nici un apartament cu acest numar\n");
}

const TElem Repo::search(const TElem& a) const
{
    auto rez = find(list.begin(), list.end(), a);
    if (rez != list.end())
        return list.at(rez - list.begin());
    throw RepoException("Nu exista nici un apartament cu acest numar\n");
}



