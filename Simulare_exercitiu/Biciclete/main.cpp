#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Service.h"
#include "GUI.h"
#include "Teste.h"

int main(int argc, char *argv[])
{

    Teste t;
    t.run_all_test();
    QApplication a(argc, argv);
    
    Repo rep{ "produse.txt" };
    Service serv{ rep };
    GUI app{ serv };
    app.show();

    return a.exec();
}
