#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qlistwidget.h>
#include <qlayout.h>
#include "Observer.h"
#include <qpushbutton.h>

class Mini_win:public QWidget, public Observer
{
private:
	Service& serv;
	string status;
	QListWidget* lista = new QListWidget;
	QPushButton* btn_open = new QPushButton("Open");
	QPushButton* btn_inprogress = new QPushButton("Inprogress");
	QPushButton* btn_closed = new QPushButton("Closed");

public:
	Mini_win(Service& serv, string status) : serv{ serv }, status{ status }{
		serv.add_observer(this);
		load_data();
		init_comp();
		init_connection();
		this->setWindowTitle(QString::fromStdString(status));
	}

	void load_data();

	void init_comp();

	void init_connection();

	void update() override;

	void update(string status);

	~Mini_win() {
		serv.remove_observer(this);
	}
};

