#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>

void GUI::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(list);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Nume", txt_nume);
	ly_form->addRow("Tara", txt_tara);
	ly_form->addRow("Pret", txt_pret);
	ly_form->addWidget(btn_filtru);
	ly_form->addWidget(btn_sort);

	ly_main->addLayout(ly_form);

}

void GUI::init_connection()
{
	QObject::connect(btn_filtru, &QPushButton::clicked, this, &GUI::filtru);
	QObject::connect(list, &QListWidget::itemSelectionChanged, this, &GUI::get_info);
	QObject::connect(btn_sort, &QPushButton::clicked, this, &GUI::sortare);
}

void GUI::load_data(const vector<Coffee>& lista_cof)
{
	list->clear();
	for (const auto& cof : lista_cof)
	{
		list->addItem(QString::fromStdString(cof.get_nume()));
	}
}

void GUI::filtru()
{
	curata_culoare();
	string tara = txt_tara->text().toStdString();
	double pret = txt_pret->text().toDouble();
	vector<Coffee> lista_cof{ serv.filtrare(tara, pret) };

	for (const auto& cof : lista_cof)
	{
		auto item = list->findItems(QString::fromStdString(cof.get_nume()), Qt::MatchFlag());
		item[0]->setBackground(QBrush{ "red" });
	}
}

void GUI::get_info()
{
	auto select_item = list->selectedItems();
	if (select_item.isEmpty())
	{
		txt_nume->setText("");
		txt_tara->setText("");
		txt_pret->setText("");
	}
	else
	{
		auto sel_item = select_item[0];
		string nume = sel_item->text().toStdString();

		Coffee cof = serv.search(nume);
		txt_nume->setText(QString::fromStdString(cof.get_nume()));
		txt_tara->setText(QString::fromStdString(cof.get_tara()));
		txt_pret->setText(QString::number(cof.get_pret()));
	}
}

void GUI::curata_culoare()
{
	int dim = list->count();
	for (int i = 0; i < dim; ++i)
	{
		list->item(i)->setBackground(QBrush{ Qt::white });
	}
}

void GUI::sortare()
{
	curata_culoare();
	load_data(serv.sortare());
}

