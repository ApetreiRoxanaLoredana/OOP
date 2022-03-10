#include "CosGUI.h"
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qmessagebox.h>
#include "Exception.h"


void CosGUI::init_GUI_comp()
{
	auto ly_main = new QHBoxLayout;
	setLayout(ly_main);

	auto ly_list = new QVBoxLayout;
	ly_list->addWidget(list_cos);

	auto ly_random = new QHBoxLayout;
	ly_random->addWidget(txt_random);
	ly_random->addWidget(btn_random);

	auto ly_add = new QHBoxLayout;
	ly_add->addWidget(txt_ap);
	ly_add->addWidget(btn_add);

	auto ly_export = new QHBoxLayout;
	ly_export->addWidget(txt_export);
	ly_export->addWidget(btn_export);

	ly_list->addLayout(ly_random);
	ly_list->addLayout(ly_add);
	ly_list->addLayout(ly_export);

	ly_main->addLayout(ly_list);

	auto ly_btn = new QVBoxLayout;
	ly_btn->addWidget(btn_goleste);
	ly_btn->addWidget(btn_exit);

	ly_main->addLayout(ly_btn);

}

void CosGUI::load_data(const std::vector<Apartament>& list_ap)
{
	list_cos->clear();
	for (const auto& ap : list_ap)
	{
		auto item = new QListWidgetItem(QString::fromStdString(ap.get_nume()));
		item->setData(Qt::UserRole, QString::number(ap.get_apartament()));
		list_cos->addItem(item);
	}
}

void CosGUI::init_connect()
{

	QObject::connect(btn_random, &QPushButton::clicked, this, &CosGUI::add_random_qui);
	QObject::connect(btn_exit, &QPushButton::clicked, [&]() {close();});
	QObject::connect(btn_goleste, &QPushButton::clicked, this, &CosGUI::goleste_gui);
	QObject::connect(btn_add, &QPushButton::clicked, this, &CosGUI::add_gui);
	QObject::connect(btn_export, &QPushButton::clicked, this, &CosGUI::export_gui);
}

void CosGUI::goleste_gui()
{
	serv.goleste_cos();
	load_data(serv.get_cos());
}

void CosGUI::add_random_qui()
{
	try {
		serv.random_ap_existent(txt_random->text().toInt());
		load_data(serv.get_cos());
	}
	catch (const ServiceException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void CosGUI::add_gui()
{
	if (txt_ap->text() != "")
	{
		try {
			serv.add_ap_existent(txt_ap->text().toInt());
			load_data(serv.get_cos());
		}
		catch (const CosException& ex) {
			QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
		}
		catch (const RepoException& ex) {
			QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
		}
	}
	else
		QMessageBox::warning(nullptr, "warning", "Introdu un numar de apartament");
}

void CosGUI::export_gui()
{
	if(txt_export->text() != "")
		serv.export_list(txt_export->text().toStdString());
	else
		QMessageBox::warning(nullptr, "warning", "Introdu un nume de fisier");
}

void CosGUI::update()
{
	load_data(serv.get_cos());
}



