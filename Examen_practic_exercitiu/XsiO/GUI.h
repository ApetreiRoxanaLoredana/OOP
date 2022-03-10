#pragma once
#include "Service.h"
#include "MyTableModel.h"
#include <qwidget.h>
#include <qtableview.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

class GUI: public QWidget
{
private:
	Service& serv;
	QTableView* tabel = new QTableView;
	MyTableModel* model = new MyTableModel(serv.get_lista_sort_stare());
	QLineEdit* txt_dim = new QLineEdit;
	QLineEdit* txt_tabla = new QLineEdit;
	QLineEdit* txt_jucator = new QLineEdit;

	QLineEdit* txt_id2 = new QLineEdit;
	QLineEdit* txt_dim2 = new QLineEdit;
	QLineEdit* txt_tabla2 = new QLineEdit;
	QLineEdit* txt_jucator2 = new QLineEdit;
	QLineEdit* txt_stare2 = new QLineEdit;
	QPushButton* btn_add = new QPushButton("Adauga");
	QPushButton* btn_modifica = new QPushButton("Modifica");
	vector<vector<QPushButton*>> butoane{ 5 };
	vector<QHBoxLayout*> ly{ 5 };
	QHBoxLayout* ly_main = new QHBoxLayout;
	QVBoxLayout* ly_tabla = new QVBoxLayout;

public:
	GUI(Service& serv) : serv{ serv } {
		tabel->setModel(model);

		for (int i = 0; i < 5; ++i)
		{
			ly[i] = new QHBoxLayout;
			butoane[i] = vector<QPushButton*>{ 5 };
			for (int j = 0; j < 5; ++j)
				butoane[i][j] = new QPushButton();
		}

		load_data(serv.get_lista_sort_stare());
		init_comp();
		init_connection();
	}

	void load_data(const vector<Joc>& lista_joc);

	void init_comp();

	void init_connection();

	void add();

	void update();

	void joaca(int i, int j);


};

