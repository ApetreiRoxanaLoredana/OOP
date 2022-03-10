#pragma once
#include <vector>
#include "Domain.h"
//#include "MyVector.h"
#include "Repo_abstract.h"
using std::vector;

typedef Apartament TElem;
typedef vector<TElem> VA;

class Repo : public Repo_abs
{
private:
	VA list;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	Repo() noexcept {};

	/// <summary>
	/// Nu perimite copierea
	/// </summary>
	/// <param name="a">obiect de tipul Repo</param>
	Repo(const Repo& a) = delete;

	virtual ~Repo() = default;

	/// <summary>
	/// Retruneaza lista de apartamente
	/// </summary>
	/// <returns>lista de apartamente</returns>
	const VA& get_list() noexcept override;

	/// <summary>
	/// Returneaza dimensiunea listei
	/// </summary>
	/// <returns>dimensiunea listei</returns>
	int get_dim() const noexcept override;

	/// <summary>
	/// Adauga un apartament in lista
	/// Arunca RepoException daca exista deja un apartament cu numarul respectiv
	/// </summary>
	/// <param name="a">obiect de tipul TElem</param>
	virtual void add(const TElem& a) override;

	/// <summary>
	/// Modifica apartamentul care are numarul respectiv
	/// cu un alt nume de prorietar, suprafata si tip
	/// Arunca RepoException daca nu exista un apartament cu numarul resoectiv
	/// </summary>
	/// <param name="a">obiect de tipul Apartament</param>
	virtual void update(const TElem& a) override;

	/// <summary>
	/// Sterge din lista apartamentul care are numarul apartamentului a
	/// Arunca RepoException daca nu exista un apartament cu numarul resoectiv
	/// </summary>
	/// <param name="a">obiect de tipul Apartament</param>
	virtual void remove(const TElem& a) override;

	/// <summary>
	/// Cauta apartamentul care are numarul apartamentului respectiv
	/// Returneaza apartamentul gasit
	/// Arunca RepoException daca nu exista un apartament cu numarul resoectiv
	/// </summary>
	/// <param name="a">un obiect de tipul TElem</param>
	/// <returns>apartamentul cu numarul respectiv</returns>
	const TElem search(const TElem& a) const override;

};

