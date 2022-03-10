#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repo rep{ "fisi.txt", "fisi_istoric.txt" };
    Service serv{ rep };
    GUI app{ serv };
    app.show();

    return a.exec();
}
