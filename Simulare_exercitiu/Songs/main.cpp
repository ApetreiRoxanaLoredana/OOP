#include "Songs.h"
#include "teste.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
#include "repository.h"
#include "validator.h"
#include "controller.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    Teste t{};
    t.run_all_test();

    Validator val;
    Repo rep{ "fisier.txt" };
    Controller contr{ rep, val };
    GUI app{ contr };
    app.show();

    return a.exec();
}
