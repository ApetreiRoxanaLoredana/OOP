#pragma once
#include <qwidget.h>
#include "controller.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>

class GUI: public QWidget
{
private:
	Controller& contr;
	QListWidget* list = new QListWidget;
	QPushButton* btn_modifica = new QPushButton("Modifica");
	QPushButton* btn_sorteaza = new QPushButton("Sorteaza");
	QPushButton* btn_sterge = new QPushButton("Sterge");
	QPushButton* btn_rang = new QPushButton("Raport");
	QLineEdit* txt_id = new QLineEdit;
	QLineEdit* txt_titlu = new QLineEdit;
	QLineEdit* txt_autor = new QLineEdit;
	QLineEdit* txt_rang = new QLineEdit;
	QLineEdit* txt_r1 = new QLineEdit;
	QLineEdit* txt_r2 = new QLineEdit;
	QLineEdit* txt_r3 = new QLineEdit;
	QLineEdit* txt_r4 = new QLineEdit;
	QLineEdit* txt_r5 = new QLineEdit;

public:
	GUI(Controller& contr):contr{contr}{
		init_gui_comp();
		load_data(contr.get_lista());
		init_connect();
	}

	void init_gui_comp();

	void init_connect();

	void load_data(const vector<Melodie>& lista_mel);

	void get_info();

	void modifica();

	void sorteaza();

	void sterge();

	void ranguri();
};

