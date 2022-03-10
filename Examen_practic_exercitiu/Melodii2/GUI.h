#pragma once
#include "Service.h"
#include <qtableview.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qlayout.h>
#include "qformlayout.h"
#include "MyModel.h"
#include <qmessagebox.h>
#include <qpainter.h>
#include <qslider.h>

class GUI: public QWidget
{
private:
	Service& serv;
	QTableView* tabel = new QTableView;
	MyModel* model = new MyModel(serv.get_lista_sort_rank());
	QLineEdit* txt_titlu = new QLineEdit;
	QSlider* slider = new QSlider;
	QPushButton* btn_update = new QPushButton("Modifica");
	QPushButton* btn_remove = new QPushButton("Sterge");

public:
	GUI(Service& serv) :serv{ serv } {
		tabel->setModel(model);
		load_data(serv.get_lista_sort_rank());
		init_comp();
		init_connection();
	}

	GUI(const GUI& ot) = delete;

	void load_data(const vector<Melodie>& lista_mel);

	void init_comp();

	void init_connection();

	void update();

	void remove();

	void paintEvent(QPaintEvent*) override;
};

