#include <QtWidgets/QApplication>
#include "GUI.h"
#include "Validator.h"
#include "Repo.h"
#include "Repo_file.h"
#include "Service.h"
#include "Teste.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "CosDesenareGUI.h"
#include "GUIModel.h"

int main(int argc, char** argv)
{
    {
        Teste t{};
        t.all_test();

        QApplication a(argc, argv);
        Repo_file rep{ "date.txt" };
        Validator val{};
        Service serv{ rep, val };
        GUIModel consola{ serv };
        consola.show();

        return a.exec();
    }
    //_CrtDumpMemoryLeaks();
}
