#pragma once
#include "ActiuneUndo.h"
#include "Domain.h"
#include "Repo.h"
#include "Repo_abstract.h"

class UndoSterge : public ActiuneUndo
{
private:

	TElem elem_sters;
	Repo_abs& rep;

public:

	UndoSterge(Repo_abs& rep, const TElem& e) : rep{ rep }, elem_sters{ e }{};

	void doUndo() override {
		rep.add(elem_sters);
	}

};

