
#include <QtWidgets/QApplication>
#include "repository.h"
#include "service.h"
#include "validator.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repo rep{ "fisi.txt" };
    Validator val{};
    Service serv{ rep, val };
    GUI consola{ serv };
    consola.show();
 
    return a.exec();
}
