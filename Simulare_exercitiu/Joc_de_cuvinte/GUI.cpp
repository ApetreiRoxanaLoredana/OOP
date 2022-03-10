#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <random>
#include <stdlib.h>
#include <algorithm>
#include <qmessagebox.h>

void GUI::init_comp_gui()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(list);
	
	QFormLayout* ly_form = new QFormLayout;
	lbl_scor->setText("0");
	ly_form->addRow("Scor: ", lbl_scor);
	ly_form->addRow("Cuvant: ", lbl_cuv_random);
	ly_form->addRow("Cuvnatul e: ", txt_cuvant);
	ly_form->addWidget(btn_ghiceste);

	ly_main->addLayout(ly_form);
}

void GUI::init_connection()
{
	QObject::connect(btn_ghiceste, &QPushButton::clicked, this, &GUI::ghiceste);
}

void GUI::load_data(const vector<Cuvant>& lista_cuv)
{
	list->clear();
	for (const auto& cuv : lista_cuv)
	{
		list->addItem(QString::fromStdString(cuv.get_cuvant()));
	}
}

void GUI::get_random_cuv()
{
	Cuvant cuv = serv.get_cuv_random();
	cuv_curent = cuv;
	string cuv_random = cuv.get_cuvant();

	while (1)
	{
		int cnt = 0;
		int poz1 = rand() % cuv.get_cuvant().size();
		int poz2 = rand() % cuv.get_cuvant().size();

		std::swap(cuv_random[poz1], cuv_random[poz2]);

		for (int i = 0; i < cuv_random.size(); i++)
			if (cuv.get_cuvant()[i] != cuv_random[i])
				cnt++;
		if (cnt > cuv_random.size() / 2)
			break;
	}

	lbl_cuv_random->setText(QString::fromStdString(cuv_random));
}

void GUI::ghiceste()
{
	string cuv_u = txt_cuvant->text().toStdString();

	if (cuv_u.size() != cuv_curent.get_cuvant().size())
	{
		QMessageBox::warning(this, "warning", "Cuvantul nu are aceasi dimenisune");
		return;
	}

	if (cuv_u == cuv_curent.get_cuvant())
	{
		incercari = 0;
		int scor_initial = lbl_scor->text().toInt();
		scor_initial += cuv_curent.get_scor();
		lbl_scor->setText(QString::number(scor_initial));
		txt_cuvant->setText("");
		list->addItem(QString::fromStdString(cuv_curent.get_cuvant()));
		serv.add_cuv(cuv_curent.get_cuvant());
		get_random_cuv();
	}
	else
	{
		incercari++;
		int scor_initial = lbl_scor->text().toInt();
		scor_initial--;
		lbl_scor->setText(QString::number(scor_initial));
	}

	if (incercari == 3)
	{
		QMessageBox::information(this, "Anunt", "Ai pierdut");
		int scor_initial = lbl_scor->text().toInt();

		serv.reset(scor_initial);

		scor_initial = 0;
		lbl_scor->setText(QString::number(scor_initial));

		list->clear();
		txt_cuvant->setText("");
		get_random_cuv();
	}
}
