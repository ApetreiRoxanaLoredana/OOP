#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include "Service.h"
#include <stdio.h>
#include <qpen.h>
#include "Observer.h"

class CosDesenareGUI: public QWidget, public Observer
{
private:
	Service& serv;

public:
	CosDesenareGUI(Service& serv) :serv{ serv } {
		serv.add_observer(this);
	};

	void paintEvent(QPaintEvent*) override {
		QPainter p{ this };

		int x, y;
		for (const auto& ap: serv.get_cos())
		{
			x = rand() % 500;
			y = rand() % 400;
			p.setPen(QPen{ Qt::red });
			
			p.drawImage(QRect(x, y, 70, 70), QImage("house.png"));
			p.drawText(QRect(x + 30, y + 20, 20, 20), QString::number(ap.get_apartament()));
		}
	}

	void update() override {
		repaint();
	}

	~CosDesenareGUI() {
		serv.remove_observer(this);
	}
};

