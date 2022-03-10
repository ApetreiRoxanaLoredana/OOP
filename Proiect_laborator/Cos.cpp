#include "Cos.h"
#include "Cos.h"
#include <vector>
#include <fstream>
#include "Exception.h"
using std::vector;

void Cos::add(const TElem& ap)
{
    auto rez = find(cos.begin(), cos.end(), ap);
    if (rez != cos.end())
        throw CosException("Exista deja un apartament cu acest numar\n");

    cos.push_back(ap);
}

void Cos::remove(const TElem& ap)
{
    auto rez = find(cos.begin(), cos.end(), ap);
    if (rez != cos.end())
    {
        cos.erase(rez);
        return;
    }
    throw CosException("Nu exista nici un apartament cu acest numar\n");
}

int Cos::get_dim() const noexcept
{
    return (int)cos.size();
}

void Cos::goleste() noexcept
{
    cos.clear();
}

void Cos::export_csv(string file_name) const
{
    std::ofstream fout(file_name, std::ios::trunc);
    for (const auto& a : cos)
    {
        fout << a.get_apartament() << ",";
        fout << a.get_nume() << ",";
        fout << a.get_suprafata() << ",";
        fout << a.get_tip() << '\n';
    }
    fout.close();
}

const std::vector<TElem>& Cos::get_cos() const noexcept
{
    return cos;
}
