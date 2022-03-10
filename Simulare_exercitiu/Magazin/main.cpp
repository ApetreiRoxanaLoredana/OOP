#include "Service.h"
#include "Repo.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Teste.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    
    Teste t;
    t.run_all_test();

    Repo rep{ "fisi.txt" };
    Service serv{ rep };
    GUI app{ serv };
    app.show();

   return a.exec();
}
