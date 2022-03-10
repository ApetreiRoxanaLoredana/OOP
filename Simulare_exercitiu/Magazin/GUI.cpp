#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>


void GUI::load_data(const vector<Produs>& lista_p)
{
	this->lista->clear();
	for (const auto& p : lista_p)
	{
		auto item = new QListWidgetItem(QString::fromStdString(p.get_description()) + ", " + QString::number(p.get_count()) + ", " + QString::number(p.get_price()));
		item->setData(Qt::UserRole, QString::number(p.get_id()));
		lista->addItem(item);
	}

	auto price = serv.get_total_price();
	txt_pret_total->setText(QString::number(price));
}

void GUI::init_comp_gui()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);

	ly_main->addWidget(lista);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Pret total", txt_pret_total);
	ly_form->addRow("Numarul de produse", txt_count);
	ly_form->addWidget(btn_inc);

	ly_main->addLayout(ly_form);
}

void GUI::init_connection()
{
	QObject::connect(btn_inc, &QPushButton::clicked, this, &GUI::update);
}

void GUI::update()
{
	try {

		auto item = lista->selectedItems();
		if (!item.isEmpty())
		{
			auto id = item[0]->data(Qt::UserRole).toInt();
			serv.update(id, txt_count->text().toInt());
			load_data(serv.sortare());
		}
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(this, "warning", QString::fromStdString(ex.get_message()));
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(this, "warning", QString::fromStdString(ex.get_message()));
	}
}


