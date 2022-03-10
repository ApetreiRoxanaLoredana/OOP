
#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Service.h"
#include "GUI.h"
#include "Validator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo rep{ "fisi.txt" };
    Validator val;
    Service serv{ rep, val };
    GUI consola{ serv };
    consola.show();
    
    return a.exec();
}
