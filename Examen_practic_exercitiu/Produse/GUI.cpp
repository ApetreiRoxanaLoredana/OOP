#include "GUI.h"
#include "mini_fereastra.h"
#include <qformlayout.h>
#include <qmessagebox.h>

void GUI::load_data(const vector<Produs>& lista_p)
{
	double pret = slider_pret->value();
	txt_pret->setText(QString::number(pret));
	vector<Produs> lista_filtru = serv.get_lista_filtru_pret(pret);
	tabel->setRowCount(0);
	tabel->setColumnCount(5);
	int i = 0;

	for (const auto& p : lista_p)
	{
		auto item0 = new QTableWidgetItem();
		auto item1 = new QTableWidgetItem();
		auto item2 = new QTableWidgetItem();
		auto item3 = new QTableWidgetItem();
		auto item4 = new QTableWidgetItem();
		item0->setText(QString::number(p.get_id()));
		item1->setText(QString::fromStdString(p.get_nume()));
		item2->setText(QString::fromStdString(p.get_tip()));
		item3->setText(QString::number(p.get_pret()));
		item4->setText(QString::number(serv.get_vocale(p)));

		auto it = std::find(lista_filtru.begin(), lista_filtru.end(), p);
		if (it != lista_filtru.end())
		{
			item0->setBackground(Qt::red);
			item1->setBackground(Qt::red);
			item2->setBackground(Qt::red);
			item3->setBackground(Qt::red);
			item4->setBackground(Qt::red);
		}
		tabel->insertRow(i);
		tabel->setItem(i, 0, item0);
		tabel->setItem(i, 1, item1);
		tabel->setItem(i, 2, item2);
		tabel->setItem(i, 3, item3);
		tabel->setItem(i, 4, item4);
		i++;
	}
}

void GUI::init_connection()
{
	QObject::connect(btn_add, &QPushButton::clicked, this, &GUI::add);
	QObject::connect(tabel, &QTableWidget::itemSelectionChanged, this, &GUI::get_info);
	QObject::connect(slider_pret, &QSlider::valueChanged, [&](){load_data(serv.get_lista_sort_pret());});
}

void GUI::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(tabel);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Id: ", txt_id);
	ly_form->addRow("Nume: ", txt_nume);
	ly_form->addRow("Tip: ", txt_tip);
	ly_form->addRow("Pret: ", txt_pret);
	ly_form->addWidget(btn_add);
	ly_form->addWidget(slider_pret);

	ly_main->addLayout(ly_form);
}

void GUI::add()
{
	int id = txt_id->text().toInt();
	string nume = txt_nume->text().toStdString();
	string tip = txt_tip->text().toStdString();
	double pret = txt_pret->text().toDouble();
	try {
		serv.add(id, nume, tip, pret);
		load_data(serv.get_lista_sort_pret());
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
		return;
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
		return;
	}

	auto it = std::find(tipuri.begin(), tipuri.end(), tip);
	if (it != tipuri.end())
		return;
	tipuri.push_back(tip);
	Mini_fereastra* a = new Mini_fereastra{ serv, tip };
	a->show();
	
}

void GUI::get_info()
{
	auto sel = tabel->selectedItems();
	if (sel.isEmpty())
	{
		txt_id->setText("");
		txt_nume->setText("");
		txt_tip->setText("");
		txt_pret->setText("");
		return;
	}

	auto sel_item = sel.at(0);
	int row = sel_item->row();
	auto p = serv.search(tabel->item(row, 0)->text().toInt());
	txt_id->setText(QString::number(p.get_id()));
	txt_nume->setText(QString::fromStdString(p.get_nume()));
	txt_tip->setText(QString::fromStdString(p.get_tip()));
	txt_pret->setText(QString::number(p.get_pret()));

}

void GUI::filtru()
{
	
}

void GUI::create_mini_win()
{
	for (const auto& p : serv.get_lista_sort_pret())
	{
		auto it = std::find(tipuri.begin(), tipuri.end(), p.get_tip());
		if (it != tipuri.end())
			continue;
		Mini_fereastra* a = new Mini_fereastra(serv, p.get_tip());
		a->show();
		tipuri.push_back(p.get_tip());
	}
}
