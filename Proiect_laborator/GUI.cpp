#include "GUI.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qframe.h>
#include <qdebug.h>
#include <typeinfo>
#include <vector>
#include "Exception.h"

void GUI::init_GUI_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);

	auto ly_list_btn_sort = new QVBoxLayout;
	ly_list_btn_sort->addWidget(list);
	combo_reverse->addItem("Crescator");
	combo_reverse->addItem("Descrescator");
	combo_reverse->setCurrentIndex(0);
	ly_list_btn_sort->addWidget(combo_reverse);

	auto ly_sort_btn = new QHBoxLayout;
	ly_sort_btn->addWidget(btn_sort_by_nume);
	ly_sort_btn->addWidget(btn_sort_by_sup);

	ly_list_btn_sort->addLayout(ly_sort_btn);
	combo_reverse2->addItem("Crescator 2");
	combo_reverse2->addItem("Descrescator 2");
	combo_reverse2->setCurrentIndex(0);
	ly_list_btn_sort->addWidget(combo_reverse2);
	ly_list_btn_sort->addWidget(btn_sort_by_tip_sup);

	ly_main->addLayout(ly_list_btn_sort);
	
	auto ly_form = new QFormLayout;
	ly_form->addRow("Numar", txt_numar);
	ly_form->addRow("Nume proprietar", txt_nume);
	ly_form->addRow("Suprafata", txt_suprafata);
	ly_form->addRow("Tip", txt_tip);

	auto ly_btn1 = new QHBoxLayout;
	ly_btn1->addWidget(btn_add);
	ly_btn1->addWidget(btn_remove);
	ly_btn1->addWidget(btn_update);
	ly_btn1->addWidget(btn_search);

	auto ly_btn2 = new QHBoxLayout;
	ly_btn2->addWidget(btn_filtru_suprafata);
	ly_btn2->addWidget(btn_filtru_tip);
	

	auto ly_form2 = new QFormLayout;
	ly_form2->addRow("Suprafata", txt_suprafata_filtru);
	ly_form2->addRow("Tip", txt_tip_filtru);

	auto ly_form_btn = new QVBoxLayout;
	ly_form_btn->addLayout(ly_form);
	ly_form_btn->addLayout(ly_btn1);

	//chestii pt cos
	auto line1 = new QFrame();
	line1->setFrameShape(QFrame::HLine);
	line1->setFrameShadow(QFrame::Raised);
	line1->setLineWidth(3);
	ly_form_btn->addWidget(line1);

	auto ly_form_cos_id = new QFormLayout;
	ly_form_cos_id->addRow("Numarul apartamentului: ", txt_id_cos);
	ly_form_cos_id->addWidget(btn_add_cos);
	ly_form_cos_id->addWidget(btn_remove_cos);
	ly_form_btn->addLayout(ly_form_cos_id);

	auto ly_form_cos_nr = new QFormLayout;
	ly_form_cos_nr->addRow("Numarul de apartamete: ", txt_genereaza_cos);
	ly_form_cos_nr->addWidget(btn_genereaza_cos);
	ly_form_cos_nr->addWidget(btn_goleste_cos);

	ly_form_btn->addLayout(ly_form_cos_nr);

	auto ly_btn_cos = new QHBoxLayout;
	ly_btn_cos->addWidget(btn_cos);
	ly_btn_cos->addWidget(btn_cos_desenare);
	ly_form_btn->addLayout(ly_btn_cos);
	//gata cu cosul

	auto line2 = new QFrame();
	line2->setFrameShape(QFrame::HLine);
	line2->setFrameShadow(QFrame::Raised);
	line2->setLineWidth(3);

	ly_form_btn->addWidget(line2);
	ly_form_btn->addLayout(ly_form2);
	ly_form_btn->addLayout(ly_btn2);

	auto line3 = new QFrame();
	line3->setFrameShape(QFrame::HLine);
	line3->setFrameShadow(QFrame::Raised);
	line3->setLineWidth(3);
	ly_form_btn->addWidget(line3);

	auto ly_report = new QHBoxLayout;
	ly_report->addWidget(btn_report);
	ly_report->addWidget(btn_undo);

	ly_form_btn->addLayout(ly_report);
	ly_form_btn->addWidget(btn_exit);

	ly_main->addLayout(ly_form_btn);

	//ly_main->addWidget(tabel);
}

void GUI::set_color()
{
	btn_add->setStyleSheet("background-color: #F3A6F9; color: #ff1a75");
	btn_remove->setStyleSheet("background-color: #FF4FCC");
	btn_update->setStyleSheet("background-color: #9867FF");
	btn_search->setStyleSheet("background-color: #ffb3ff; color: #ff1a75");
	combo_reverse->setStyleSheet("background-color: #9999ff; color: #0000ff");
	btn_sort_by_nume->setStyleSheet("background-color: #9999ff; color: #0000ff");
	btn_sort_by_sup->setStyleSheet("background-color: #9999ff; color: #0000ff");
	combo_reverse2->setStyleSheet("background-color: #e699ff; color: #4d0066");
	btn_sort_by_tip_sup->setStyleSheet("background-color: #e699ff; color: #4d0066");

}

void GUI::load_date(const VA& list_ap)
{
	list->clear();
	tabel->setRowCount(0);

	int i = 0;

	for (const auto& ap : list_ap)
	{
		auto item = new QListWidgetItem(QString::fromStdString(ap.get_nume()));
		item->setData(Qt::UserRole, QString::number(ap.get_apartament()));
		list->addItem(item);
		
		auto item0 = new QTableWidgetItem{};
		auto item1 = new QTableWidgetItem{};
		auto item2 = new QTableWidgetItem{};
		auto item3 = new QTableWidgetItem{};
		item0->setText(QString::number(ap.get_apartament()));
		item1->setText(QString::fromStdString(ap.get_nume()));
		item2->setText(QString::number(ap.get_suprafata()));
		item3->setText(QString::fromStdString(ap.get_tip()));
		item0->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		item1->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		item2->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		item3->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		
		tabel->insertRow(i);

		tabel->setItem(i, 0, item0);
		tabel->setItem(i, 1, item1);
		tabel->setItem(i, 2, item2);
		tabel->setItem(i, 3, item3);
		
		i++;
	}
}

void GUI::init_connect()
{
	
	QObject::connect(btn_exit, &QPushButton::clicked, [&]() {close();});
	QObject::connect(list, &QListWidget::itemSelectionChanged, this, &GUI::get_info);
	QObject::connect(tabel, &QTableWidget::itemSelectionChanged, this, &GUI::get_info_tabel);
	QObject::connect(btn_add, &QPushButton::clicked, this, &GUI::add_gui);
	QObject::connect(btn_update, &QPushButton::clicked, this, &GUI::update_gui);
	QObject::connect(btn_remove, &QPushButton::clicked, this, &GUI::remove_gui);
	QObject::connect(btn_sort_by_nume, &QPushButton::clicked, this, &GUI::sort_by_nume_qui);
	QObject::connect(btn_sort_by_sup, &QPushButton::clicked, this, &GUI::sort_by_suprafata_gui);
	QObject::connect(btn_sort_by_tip_sup, &QPushButton::clicked, this, &GUI::sort_by_tip_suprafata_gui);
	QObject::connect(btn_search, &QPushButton::clicked, this, &GUI::search_gui);
	QObject::connect(btn_filtru_suprafata, &QPushButton::clicked, this, &GUI::filtru_suprafata_gui);
	QObject::connect(btn_filtru_tip, &QPushButton::clicked, this, &GUI::filtru_tip_gui);
	QObject::connect(btn_report, &QPushButton::clicked, this, &GUI::raport_gui);
	QObject::connect(btn_undo, &QPushButton::clicked, this, &GUI::undo_gui);
	//QObject::connect(btn_cos, &QPushButton::clicked, [&]() {cos->show();});

	//pt cos
	QObject::connect(btn_add_cos, &QPushButton::clicked, this, &GUI::add_cos);
	QObject::connect(btn_remove_cos, &QPushButton::clicked, this, &GUI::remove_cos);
	QObject::connect(btn_genereaza_cos, &QPushButton::clicked, this, &GUI::genereaza_ap_cos);
	QObject::connect(btn_goleste_cos, &QPushButton::clicked, this, &GUI::goleste_cos);
	QObject::connect(btn_cos, &QPushButton::clicked, this, [&]() {auto cos = new CosGUI{ serv }; cos->show();});
	QObject::connect(btn_cos_desenare, &QPushButton::clicked, this, [&]() {auto cos = new CosDesenareGUI{ serv };cos->show();});
}

void GUI::get_info()
{
	auto sel = list->selectedItems();
	if (sel.isEmpty())
	{
		txt_numar->setText("");
		txt_nume->setText("");
		txt_suprafata->setText("");
		txt_tip->setText("");
		txt_id_cos->setText("");
	}
	else
	{
		auto sel_item = sel.at(0);
		auto numar = sel_item->data(Qt::UserRole).toString();
		txt_numar->setText(numar);
		txt_nume->setText(sel_item->text());
		auto ap = serv.search_ap(numar.toInt());
		txt_suprafata->setText(QString::number(ap.get_suprafata()));
		txt_tip->setText(QString::fromStdString(ap.get_tip()));
		txt_id_cos->setText(numar);
	}
}

void GUI::get_info_tabel()
{
	auto selt = tabel->selectedItems();
	if (selt.isEmpty())
	{
		txt_numar->setText("");
		txt_nume->setText("");
		txt_suprafata->setText("");
		txt_tip->setText("");
	}
	else
	{
		auto selt_item = selt.at(0);
		int row = selt_item->row();
		auto ap = serv.search_ap(tabel->item(row, 0)->text().toInt());
		txt_numar->setText(QString::number(ap.get_apartament()));
		txt_nume->setText(QString::fromStdString(ap.get_nume()));
		txt_suprafata->setText(QString::number(ap.get_suprafata()));
		txt_tip->setText(QString::fromStdString(ap.get_tip()));
	}
}

void GUI::add_gui()
{
	try {
		serv.add_ap(txt_numar->text().toInt(), txt_nume->text().toStdString(), txt_suprafata->text().toDouble(), txt_tip->text().toStdString());
		load_date(serv.get_lista_ap());
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::update_gui()
{
	try {
		serv.update_ap(txt_numar->text().toInt(), txt_nume->text().toStdString(), txt_suprafata->text().toDouble(), txt_tip->text().toStdString());
		load_date(serv.get_lista_ap());
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::remove_gui()
{
	try {
		serv.remove_ap(txt_numar->text().toInt());
		load_date(serv.get_lista_ap());
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::search_gui()
{
	try {

		auto ap = serv.search_ap(txt_numar->text().toInt());
		std::vector<Apartament> list_ap;
		list_ap.push_back(ap);
		load_date(list_ap);
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
	catch (const RepoException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::sort_by_nume_qui()
{
	if (combo_reverse->currentText() == "Crescator")
	{
		const VA& list_ap = serv.sortare_nume(true);
		load_date(list_ap);
	}
	else
	{
		const VA& list_ap = serv.sortare_nume(false);
		load_date(list_ap);
	}
}

void GUI::sort_by_suprafata_gui()
{
	if (combo_reverse->currentText() == "Crescator")
	{
		const VA& list_ap = serv.sortare_suprafata(true);
		load_date(list_ap);
	}
	else
	{
		const VA& list_ap = serv.sortare_suprafata(false);
		load_date(list_ap);
	}
}

void GUI::sort_by_tip_suprafata_gui()
{
	if (combo_reverse->currentText() == "Crescator" && combo_reverse2->currentText() == "Crescator 2")
	{
		const VA& list_ap = serv.sortare_tip_suprafata(true, true);
		load_date(list_ap);
	}

	if (combo_reverse->currentText() == "Crescator" && combo_reverse2->currentText() == "Descrescator 2")
	{
		const VA& list_ap = serv.sortare_tip_suprafata(true, false);
		load_date(list_ap);
	}

	if (combo_reverse->currentText() == "Descrescator" && combo_reverse2->currentText() == "Descrescator 2")
	{
		const VA& list_ap = serv.sortare_tip_suprafata(false, false);
		load_date(list_ap);
	}

	if (combo_reverse->currentText() == "Descrescator" && combo_reverse2->currentText() == "Crescator 2")
	{
		const VA& list_ap = serv.sortare_tip_suprafata(false, true);
		load_date(list_ap);
	}
}

void GUI::filtru_suprafata_gui()
{
	if (txt_suprafata_filtru->text().isEmpty())
	{
		QMessageBox::warning(nullptr, "warning", "Introdu o suprafata");
	}
	else
	{
		const VA& list_ap = serv.filtru_suprafata(txt_suprafata_filtru->text().toDouble());
		load_date(list_ap);
	}
}

void GUI::filtru_tip_gui()
{
	if (txt_tip_filtru->text().isEmpty())
	{
		QMessageBox::warning(nullptr, "warning", "Introdu un tip de apartament");
	}
	else
	{
		try {
			const VA& list_ap = serv.filtru_tip(txt_tip_filtru->text().toStdString());
			load_date(list_ap);
		}
		catch (const ValidatorException& ex) {
			QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
		}
	}
}

void GUI::raport_gui()
{
	list->clear();
	std::map<string, int> my_map = serv.raport();
	for (auto it = my_map.begin(); it != my_map.end(); it++)
		list->addItem(QString::fromStdString(it->first) + ": " + QString::number(it->second));
}

void GUI::undo_gui()
{
	try {
		serv.undo();
		load_date(serv.get_lista_ap());
	}
	catch (const ServiceException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::add_cos()
{
	if (txt_id_cos->text() != "")
	{
		try {
			serv.add_ap_existent(txt_id_cos->text().toInt());
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

void GUI::remove_cos()
{
	if (txt_id_cos->text() != "")
	{
		try {
			serv.remove_cos(txt_id_cos->text().toInt());
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

void GUI::genereaza_ap_cos()
{
	try {
		serv.random_ap_existent(txt_genereaza_cos->text().toInt());
	}
	catch (const ServiceException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::goleste_cos()
{
	serv.goleste_cos();
}

void GUI::update()
{
	load_date(serv.get_lista_ap());
}
