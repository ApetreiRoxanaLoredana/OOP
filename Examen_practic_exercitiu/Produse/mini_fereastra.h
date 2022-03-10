#pragma once
#include "service.h"
#include "observer.h"
#include <qwidget.h>
#include <qlabel.h>

class Mini_fereastra: public QWidget, public Observer
{
private:
	Service& serv;
	string tip;
	QLabel* lbl = new QLabel;
public:

	Mini_fereastra(Service& serv, string tip) :serv{ serv }, tip{ tip } {
		this->setWindowTitle(QString::fromStdString(tip));
		serv.add_observer(this);
		init_comp();
		update();
	};

	void init_comp();

	void update() override;

	~Mini_fereastra()
	{
		serv.remove_observer(this);
	}
};

