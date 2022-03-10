#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtablewidget.h>
#include <qlayout.h>
#include <qformlayout.h>
#include "Mini_win.h"
#include "Observer.h"

class GUI: public QWidget, public Observer
{
private:
	Service& serv;
	QTableWidget* tabel = new QTableWidget;
	QLineEdit* txt_id = new QLineEdit;
	QLineEdit* txt_descriere = new QLineEdit;
	QLineEdit* txt_programatori = new QLineEdit;
	QLineEdit* txt_stare = new QLineEdit;
	QLineEdit* txt_nume_p = new QLineEdit;
	QPushButton* btn_add = new QPushButton("Adauga");
	QPushButton* btn_filtru = new QPushButton("Filtru");

public:
	GUI(Service& serv) :serv{ serv } {
		serv.add_observer(this);
		Mini_win* win_open = new Mini_win{ serv, "open" };
		Mini_win* win_inprogress = new Mini_win{ serv, "inprogress" };
		Mini_win* win_closed = new Mini_win{ serv, "closed" };
		win_open->show();
		win_inprogress->show();
		win_closed->show();
		load_data(serv.get_lista_sort_stare());
		init_comp();
		init_connection();
	}

	GUI(const GUI& ot) = delete;

	void load_data(const vector<Task>& lista_task);

	void init_comp();

	void init_connection();

	void add();

	void get_info();

	void filtru();

	void update() override;

	~GUI() {
		serv.remove_observer(this);
	}
};

