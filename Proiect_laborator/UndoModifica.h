#pragma once
#include "ActiuneUndo.h"
#include "Domain.h"
#include "Repo.h"
#include "Repo_abstract.h"

class UndoModifica : public ActiuneUndo
{
private:

	TElem elem_modificat;
	Repo_abs& rep;

public:

	UndoModifica(Repo_abs& rep, const TElem& e) : rep{ rep }, elem_modificat{ e }{};

	void doUndo() override {

		rep.update(elem_modificat);
	}
};

