#include "GUI.h"
#include "Exception.h"
#include <qmessagebox.h>

void GUI::load_data(const vector<Task>& lista_task)
{
	tabel->setRowCount(0);
	tabel->setColumnCount(4);

	int i = 0;
	for (const auto& t : lista_task)
	{
		auto item0 = new QTableWidgetItem;
		auto item1 = new QTableWidgetItem;
		auto item2 = new QTableWidgetItem;
		auto item3 = new QTableWidgetItem;
		item0->setText(QString::number(t.get_id()));
		item1->setText(QString::fromStdString(t.get_descriere()));
		item2->setText(QString::fromStdString(t.get_stare()));
		item3->setText(QString::number(t.get_nr_programatori()));

		tabel->insertRow(i);
		tabel->setItem(i, 0, item0);
		tabel->setItem(i, 1, item1);
		tabel->setItem(i, 2, item2);
		tabel->setItem(i, 3, item3);
		i++;
	}
}

void GUI::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(tabel);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Id: ", txt_id);
	ly_form->addRow("Descriere: ", txt_descriere);
	ly_form->addRow("Programatori: ", txt_programatori);
	ly_form->addRow("Stare: ", txt_stare);
	ly_form->addWidget(btn_add);
	ly_form->addRow("Nume programator: ", txt_nume_p);
	ly_form->addWidget(btn_filtru);

	ly_main->addLayout(ly_form);
}

void GUI::init_connection()
{
	QObject::connect(tabel, &QTableWidget::itemSelectionChanged, this, &GUI::get_info);
	QObject::connect(btn_add, &QPushButton::clicked, this, &GUI::add);
	QObject::connect(btn_filtru, &QPushButton::clicked, this, &GUI::filtru);
}

void GUI::add()
{
	int id = txt_id->text().toInt();
	string descriere = txt_descriere->text().toStdString();
	string line_p = txt_programatori->text().toStdString();
	vector<string> programatori;
	string programator;
	std::istringstream line_stream(line_p);
	programatori.clear();
	while (!line_stream.eof())
	{
		std::getline(line_stream, programator, ';');
		programatori.push_back(programator);
	}
	string stare = txt_stare->text().toStdString();

	try {
		serv.add(id, descriere, programatori, stare);
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
	load_data(serv.get_lista_sort_stare());
}

void GUI::get_info()
{
	auto sel = tabel->selectedItems();
	if (sel.isEmpty())
	{
		txt_id->setText("");
		txt_descriere->setText("");
		txt_programatori->setText("");
		txt_stare->setText("");
		return;
	}

	auto sel_item = sel.at(0);
	int row = sel_item->row();
	auto t = serv.search(tabel->item(row, 0)->text().toInt());
	txt_id->setText(QString::number(t.get_id()));
	txt_descriere->setText(QString::fromStdString(t.get_descriere()));
	auto programatori = t.get_programatori();
	string pro;
	for (const auto& p : programatori)
	{
		pro += p;
		pro += ";";
	}
	txt_programatori->setText(QString::fromStdString(pro));
	txt_stare->setText(QString::fromStdString(t.get_stare()));
}

void GUI::filtru()
{
	load_data(serv.filtru(txt_nume_p->text().toStdString()));
}

void GUI::update()
{
	load_data(serv.get_lista_sort_stare());
}
