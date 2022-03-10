#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qobject.h>
#include <qmessagebox.h>

void GUI::init_gui_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);


	QFormLayout* ly_rang = new QFormLayout;
	ly_rang->addWidget(list);
	ly_rang->addRow("Rang 1:", txt_r1);
	ly_rang->addRow("Rang 2:", txt_r2);
	ly_rang->addRow("Rang 3:", txt_r3);
	ly_rang->addRow("Rang 4:", txt_r4);
	ly_rang->addRow("Rang 5:", txt_r5);
	ly_rang->addWidget(btn_rang);

	ly_main->addLayout(ly_rang);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Id:", txt_id);
	ly_form->addRow("Titlu:", txt_titlu);
	ly_form->addRow("Autor:", txt_autor);
	ly_form->addRow("Rang:", txt_rang);
	ly_form->addWidget(btn_modifica);
	ly_form->addWidget(btn_sorteaza);
	ly_form->addWidget(btn_sterge);

	ly_main->addLayout(ly_form);
	
	
	
}

void GUI::init_connect()
{
	QObject::connect(list, &QListWidget::itemSelectionChanged, this, &GUI::get_info);
	QObject::connect(btn_modifica, &QPushButton::clicked, this, &GUI::modifica);
	QObject::connect(btn_sorteaza, &QPushButton::clicked, this, &GUI::sorteaza);
	QObject::connect(btn_sterge, &QPushButton::clicked, this, &GUI::sterge);
	QObject::connect(btn_rang, &QPushButton::clicked, this, &GUI::ranguri);
}

void GUI::load_data(const vector<Melodie>& lista_mel)
{
	this->list->clear();
	for (const auto& mel : lista_mel)
	{
		auto item = new QListWidgetItem(QString::fromStdString(mel.get_titlu()));
		item->setData(Qt::UserRole, QString::number(mel.get_id()));
		this->list->addItem(item);
	}
}

void GUI::get_info()
{
	auto sel = list->selectedItems();
	if (sel.isEmpty())
	{
		txt_id->setText("");
		txt_titlu->setText("");
		txt_autor->setText("");
		txt_rang->setText("");
	}
	else
	{
		auto sel_item = sel.at(0);
		auto id = sel_item->data(Qt::UserRole).toString();
		txt_id->setText(id);
		txt_titlu->setText(sel_item->text());
		auto mel = contr.search(id.toInt());
		txt_autor->setText(QString::fromStdString(mel.get_autor()));
		txt_rang->setText(QString::number(mel.get_rang()));
	}
}

void GUI::modifica()
{
	try {
		contr.update_melodie(txt_id->text().toInt(), txt_titlu->text().toStdString(), txt_autor->text().toStdString(), txt_rang->text().toInt());
		load_data(contr.get_lista());
	}
	catch (ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::sorteaza()
{
	load_data(contr.sorteaza());
}

void GUI::sterge()
{
	contr.sterge(txt_id->text().toInt());
	load_data(contr.get_lista());
}

void GUI::ranguri()
{
	vector<int> lista = contr.ranguri();
	txt_r1->setText(QString::number(lista[0]));
	txt_r2->setText(QString::number(lista[1]));
	txt_r3->setText(QString::number(lista[2]));
	txt_r4->setText(QString::number(lista[3]));
	txt_r5->setText(QString::number(lista[4]));
}
