#include "Mini_win.h"
#include <iostream>
#include <algorithm>

void Mini_win::load_data()
{
	lista->clear();
	for (const auto& t : serv.get_lista_sort_stare())
	{
		auto item = new QListWidgetItem();
		if (t.get_stare() == status)
		{
			auto id = QString::number(t.get_id());
			item->setText(id);
			item->setData(Qt::UserRole, t.get_id());
			lista->addItem(item);
		}
	}
}

void Mini_win::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(lista);

	QVBoxLayout* ly_btn = new QVBoxLayout;
	ly_btn->addWidget(btn_open);
	ly_btn->addWidget(btn_inprogress);
	ly_btn->addWidget(btn_closed);

	ly_main->addLayout(ly_btn);
}

void Mini_win::init_connection()
{
	QObject::connect(btn_open, &QPushButton::clicked, this, [&]() {
		update("open");
		});
	QObject::connect(btn_inprogress, &QPushButton::clicked, this, [&]() {
		update("inprogress");
		});
	QObject::connect(btn_closed, &QPushButton::clicked, this, [&]() {
		update("closed");
		});
}

void Mini_win::update()
{
	load_data();
}

void Mini_win::update(string status_t)
{
	auto sel_item = lista->selectedItems();
	if (!sel_item.isEmpty())
	{
		auto sel = sel_item.at(0);
		int id = sel->data(Qt::UserRole).toInt();
		auto t = serv.search(id);
		serv.update(t.get_id(), t.get_descriere(), t.get_programatori(), status_t);
	}
}
