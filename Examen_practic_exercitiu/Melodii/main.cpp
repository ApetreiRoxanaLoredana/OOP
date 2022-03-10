
#include <QtWidgets/QApplication>
#include "repository.h"
#include "service.h"
#include "Teste.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    Teste t;
    t.run_all();
    QApplication a(argc, argv);
    Repo rep{ "fisi.txt" };
    Service serv{ rep };
    GUI consola{ serv };
    consola.show();
    return a.exec();
}
