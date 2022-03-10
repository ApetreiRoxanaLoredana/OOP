#pragma once
#include "Repo.h"
#include "Repo_file.h"
#include "Repo_abstract.h"
#include "Validator.h"
#include <map>
#include "Cos.h"
#include <vector>
#include "ActiuneUndo.h"

class Service: public Observable
{
private:
	Repo_abs& repo;
	Cos cos;
	const Validator& val;
	std::vector<std::unique_ptr<ActiuneUndo>> undo_actions;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="list">obiect de tip Repo</param>
	Service(Repo_abs& repo, const Validator& val) noexcept : repo{ repo }, val{ val }, cos(){};


	/// <summary>
	/// nu permite copierea unui obiect de tipul Service
	/// </summary>
	/// <param name="ot"></param>
	Service(const Service& ot) = delete;

	/// <summary>
	/// Creeaza si adauga un apartament nou in lista
	/// Arunca VlidatorException daca apartamentul nu e valid
	/// Arunca RepoException daca apartamentul exista deja
	/// </summary>
	/// <param name="numar">int</param>
	/// <param name="nume">string</param>
	/// <param name="suprafata"><double/param>
	/// <param name="tip">string</param>
	void add_ap(const int numar, const string nume, const double suprafata, const string tip);

	/// <summary>
	/// Returneaza o copie a listei
	/// </summary>
	/// <returns>o lista de apartamente</returns>
	const VA& get_lista_ap() const;

	/// <summary>
	/// Sterge apartamentul cu numarul respectiv
	/// Arunca RepoException daca nu exista nici un apartament cu acest numar
	/// </summary>
	/// <param name="numar">numarul apartamentului (int)</param>
	void remove_ap(const int numar);

	/// <summary>
	/// Modifica un apartament cu numele prorietarului, suprafata si tipul respectiv
	/// Arunca ValidatorException daca apartamentul nu e valid
	/// Arunca RepoException daca nu exista nici un apartament cu numarul resoectiv
	/// </summary>
	/// <param name="numar">int</param>
	/// <param name="nume">string</param>
	/// <param name="suprafata">double</param>
	/// <param name="tip">string</param>
	void update_ap(const int numar, const string nume, const double suprafata, const string tip);

	/// <summary>
	/// Cauta apartamentul cu numarul respectiv
	/// Arunca ValidatorException daca numarul apartamentului nu e valid
	/// Arunca RepoException daca nu exista nici un aparatment cu acest numar
	/// </summary>
	/// <param name="numar">numarul apartamentului (int)</param>
	/// <returns>apartamentul cu numarul respectiv</returns>
	const TElem search_ap(const int numar) const;

	/// <summary>
	/// Filtreaza apartamentele dupa tip
	/// Arunca ValidatorException daca tipul nu e valid
	/// </summary>
	/// <param name="tip">string</param>
	/// <returns>o lista cu toate apartamentele valide</returns>
	const VA filtru_tip(const string tip);

	/// <summary>
	/// Filtreaza apartamentele daca suprafata apartamentelor e mai mare 
	/// Arunca ValidatorException daca suprafata nu e vida
	/// </summary>
	/// <param name="suprafata">lista cu apartamentele cu suprafata mai mare</param>
	/// <returns></returns>
	const VA filtru_suprafata(const double suprafata);

	/// <summary>
	/// Sorteaza lista de apartamente dupa numele proprietarului
	/// </summary>
	/// <param name="reverse">true daca trebuie sortat crescator, false altfel</param>
	/// <returns>lista de apartamente sortata crescator/descrescator dupa numele prorietarului</returns>
	const VA sortare_nume(bool reverse);


	/// <summary>
	/// Sorteaza lista de apartamente dupa suprafata apartamentului
	/// </summary>
	/// <param name="reverse">true daca trebuie sortat crescator, false altfel</param>
	/// <returns>lista de apartamente sortata crescator/descrescator dupa suprafata apartamentului</returns>
	const VA sortare_suprafata(bool reverse);

	/// <summary>
	/// Sorteaza lista de apartamente dupa tip si suprafata, crescator sau descrescator
	/// </summary>
	/// <param name="reverse1">true - crescator, false altfel</param>
	/// <param name="reverse2"true crescator, false altfel></param>
	/// <returns></returns>
	const VA sortare_tip_suprafata(bool reverse1 = true, bool reverse2 = true);

	/// <summary>
	/// Sterge toate apartamentele din lista de notificare
	/// </summary>
	void goleste_cos() noexcept;

	/// <summary>
	/// Adauga apartamente random deja existente in lista
	/// </summary>
	/// <param name="nr"></param>
	void random_ap_existent(const int nr);

	/// <summary>
	/// Adauga in lista de notificare un apartament existent in lista
	/// Arunca RepoException daca nu exista in lista nici un apartament cu acest numar
	/// </summary>
	/// <param name="nr_ap">int</param>
	void add_ap_existent(int nr_ap);

	void remove_cos(int nr_ap);

	/// <summary>
	/// Exporta in fisierul file_name.cvs lista de notificare cu apartamente
	/// </summary>
	/// <param name="file_name">string</param>
	void export_list(string file_name);

	/// <summary>
	/// Returneaza un dictionar in care cheia e tipul apartamentului iar valoarea
	/// este numarul de aparitii a unui tip de apartamente
	/// </summary>
	/// <returns>map</returns>
	const std::map<string, int> raport();

	/// <summary>
	/// Returneaza dimenisune cosului
	/// </summary>
	/// <returns>int</returns>
	int get_dim_cos() const noexcept;

	/// <summary>
	/// Returneaza cosul
	/// </summary>
	/// <returns>un vector de TElem</returns>
	const std::vector<TElem>& get_cos() const noexcept;

	/// <summary>
	/// Reface ultima operatie
	/// </summary>
	void undo();
};

