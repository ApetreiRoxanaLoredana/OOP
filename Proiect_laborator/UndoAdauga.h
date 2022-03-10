#pragma once
#include "ActiuneUndo.h"
#include "Domain.h"
#include "Repo.h"
#include "Repo_abstract.h"

class UndoAdauga : public ActiuneUndo
{
private:
	TElem elem_adaugat;
	Repo_abs& rep;

public:
	UndoAdauga(Repo_abs& rep, const TElem& e) : rep{ rep }, elem_adaugat{ e }{};

	void doUndo() override {
		rep.remove(elem_adaugat);
	}
};

