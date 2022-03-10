#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo rep{ "fisi.txt" };
    Service serv{ rep };
    GUI consola{ serv };
    consola.show();
    
    return a.exec();
}
