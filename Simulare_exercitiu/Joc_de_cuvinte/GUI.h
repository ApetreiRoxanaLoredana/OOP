#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qlabel.h>
#include <qrandom.h>
#include "Service.h"

class GUI: public QWidget
{
private:
	Service& serv;
	int incercari = 0;
	Cuvant cuv_curent{ "", 0 };
	QListWidget* list = new QListWidget();
	QLabel* lbl_scor = new QLabel;
	QLabel* lbl_cuv_random = new QLabel;
	QLineEdit* txt_cuvant = new QLineEdit;
	QPushButton* btn_ghiceste = new QPushButton("Guess");


public:

	GUI(Service& serv) : serv{ serv } {
		init_comp_gui();
		get_random_cuv();
		init_connection();
	};

	void init_comp_gui();

	void init_connection();

	void load_data(const vector<Cuvant>& lista_cuv);

	void get_random_cuv();

	void ghiceste();
};

