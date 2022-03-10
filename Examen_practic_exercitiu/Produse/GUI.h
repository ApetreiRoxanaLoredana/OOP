#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qtablewidget.h>
#include <qslider.h>
#include "service.h"

class GUI: public QWidget
{
private:
	Service& serv;
	QTableWidget* tabel = new QTableWidget;
	QLineEdit* txt_id = new QLineEdit;
	QLineEdit* txt_nume = new QLineEdit;
	QLineEdit* txt_tip = new QLineEdit;
	QLineEdit* txt_pret = new QLineEdit;
	QPushButton* btn_add = new QPushButton("Adauga");
	QSlider* slider_pret = new QSlider;
	vector<string> tipuri;

public:
	GUI(Service& serv) : serv{ serv } {
		init_comp();
		load_data(serv.get_lista_sort_pret());
		init_connection();
		create_mini_win();
	};

	void load_data(const vector<Produs>& lista_p);

	void init_connection();

	void init_comp();

	void add();

	void get_info();

	void filtru();

	void create_mini_win();
};

