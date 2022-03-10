#include "repository.h"
#include <fstream>
#include <sstream>

void Repo::load_from_file()
{
    std::ifstream fin(file_name);
    if (!fin.is_open())
        throw std::exception();

    string line;
    string id_s, nume, tip, pret_s;

    while (!fin.eof())
    {
        std::getline(fin, line);
        if (line.find_first_not_of("\t\n\v\f\r") == string::npos)
            continue;
        std::istringstream line_stream(line);
        std::getline(line_stream, id_s, ';');
        std::getline(line_stream, nume, ';');
        std::getline(line_stream, tip, ';');
        std::getline(line_stream, pret_s);

        int id = std::stoi(id_s);
        double pret = std::stod(pret_s);

        Produs p{ id, nume, tip, pret };
        lista.push_back(p);
    }

    fin.close();
}

void Repo::store_to_file()
{
    std::ofstream fout(file_name);

    for (const auto& p : lista)
    {
        fout << p.get_id() << ";" << p.get_nume() << ";";
        fout << p.get_tip() << ";" << p.get_pret() << '\n';
    }

    fout.close();
}

const vector<Produs>& Repo::get_lista() const
{
    return lista;
}

void Repo::add(const Produs& p)
{
    auto it = find(lista.begin(), lista.end(), p);
    if (it != lista.end())
        throw RepoException("Exista deja un produs cu acest it\n");
    lista.push_back(p);
    store_to_file();
}

const Produs& Repo::search(Produs& p) const
{
    auto it = find(lista.begin(), lista.end(), p);
    if (it != lista.end())
        return lista.at(it - lista.begin());
    throw std::exception();
}
