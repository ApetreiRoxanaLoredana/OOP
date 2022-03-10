#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Songs.h"

class Songs : public QMainWindow
{
    Q_OBJECT

public:
    Songs(QWidget *parent = Q_NULLPTR);

private:
    Ui::SongsClass ui;
};
