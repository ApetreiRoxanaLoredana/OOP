#pragma once
#include "service.h"
#include "my_table_model.h"
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qtablewidget.h>
#include <qpainter.h>
#include <qtableview.h>

class GUI: public QWidget
{
private:
	Service& serv;
	QTableView* tabel = new QTableView;
	My_table_model* model = new My_table_model(serv.get_lista_sort_autor());
	QPushButton* btn_add = new QPushButton("Adauga");
	QPushButton* btn_remove = new QPushButton("Sterge");
	QLineEdit* txt_titlu = new QLineEdit;
	QLineEdit* txt_artist = new QLineEdit;
	QLineEdit* txt_gen = new QLineEdit;


public:
	GUI(Service& serv) :serv{ serv } {
		tabel->setModel(model);
		init_comp();
		load_data(serv.get_lista_sort_autor());
		init_conection();
	}

	GUI(const GUI& ot) = delete;

	void load_data(const vector<Melodie>& lista_mel);

	void init_comp();

	void init_conection();

	void add();

	void remove();

	void paintEvent(QPaintEvent*) override;
};


