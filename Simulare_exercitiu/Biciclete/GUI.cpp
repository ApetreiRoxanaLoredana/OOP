#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>

void GUI::load_data(const vector<Bicicleta>& lista_bici)
{
	tabel->setRowCount(0);
	tabel->setColumnCount(2);
	int i = 0;

	for (const auto& b : lista_bici)
	{
		auto item0 = new QTableWidgetItem();
		auto item1 = new QTableWidgetItem();
		
		item0->setText(QString::fromStdString(b.get_tip()));
		item1->setText(QString::number(b.get_pret()));
		item0->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		item1->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		item0->setData(Qt::UserRole, QString::number(b.get_id()));

		tabel->insertRow(i);

		tabel->setItem(i, 0, item0);
		tabel->setItem(i, 1, item1);

		i++;
	}
}

void GUI::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout();
	setLayout(ly_main);

	ly_main->addWidget(tabel);

	QFormLayout* ly_form = new QFormLayout();
	ly_form->addRow("Tip: ", txt_tip);
	ly_form->addWidget(btn_sterge_tip);
	ly_form->addWidget(btn_sterge_max);

	ly_main->addLayout(ly_form);
}

void GUI::init_connection()
{
	QObject::connect(btn_sterge_tip, &QPushButton::clicked, this, &GUI::sterge_tip);
	QObject::connect(btn_sterge_max, &QPushButton::clicked, this, &GUI::sterge_max);
}

void GUI::sterge_tip()
{
	string tip = txt_tip->text().toStdString();
	serv.sterge_tip(tip);
	load_data(serv.sorteaza());
}

void GUI::sterge_max()
{
	serv.sterge_max();
	load_data(serv.sorteaza());
}
