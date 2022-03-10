#include "GUIModel.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qframe.h>
#include <qdebug.h>
#include <typeinfo>
#include <vector>
#include "Exception.h"

void GUIModel::init_GUI_comp()
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

	ly_main->addWidget(tabel);
}

void GUIModel::set_color()
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

void GUIModel::load_date(const VA& list_ap)
{
	model->set_aps(list_ap);
}

void GUIModel::init_connect()
{

	QObject::connect(btn_exit, &QPushButton::clicked, [&]() {close();});
//	QObject::connect(list, &QListWidget::itemSelectionChanged, this, &GUIModel::get_info);
	//QObject::connect(tabel, &QTableWidget::itemSelectionChanged, this, &GUIModel::get_info_tabel);

	QObject::connect(list->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (list->selectionModel()->selectedIndexes().isEmpty()) {
			//nu este nimic selectat (golesc detaliile)
			txt_numar->setText("");
			txt_nume->setText("");
			txt_tip->setText("");
			txt_suprafata->setText("");
			return;
		}
		auto selIndex = list->selectionModel()->selectedIndexes().at(0);
		QString nume = selIndex.data(Qt::DisplayRole).toString();
		QString numar = selIndex.data(Qt::UserRole).toString();
		txt_nume->setText(nume);
		txt_numar->setText(numar);
		auto ap = serv.search_ap(numar.toInt());
		txt_tip->setText(QString::fromStdString(ap.get_tip()));
		txt_suprafata->setText(QString::number(ap.get_suprafata()));
		});

	QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
			//nu este nimic selectat (golesc detaliile)
			txt_numar->setText("");
			txt_nume->setText("");
			txt_tip->setText("");
			txt_suprafata->setText("");
			return;
		}
		int selRow = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto cel0Index = tabel->model()->index(selRow, 0);
		auto numar = tabel->model()->data(cel0Index, Qt::UserRole).toString();
		txt_numar->setText(numar);
		auto ap = serv.search_ap(numar.toInt());
		txt_nume->setText(QString::fromStdString(ap.get_nume()));
		txt_tip->setText(QString::fromStdString(ap.get_tip()));
		txt_suprafata->setText(QString::number(ap.get_suprafata()));
		});

	QObject::connect(btn_add, &QPushButton::clicked, this, &GUIModel::add_gui);
	QObject::connect(btn_update, &QPushButton::clicked, this, &GUIModel::update_gui);
	QObject::connect(btn_remove, &QPushButton::clicked, this, &GUIModel::remove_gui);
	QObject::connect(btn_sort_by_nume, &QPushButton::clicked, this, &GUIModel::sort_by_nume_qui);
	QObject::connect(btn_sort_by_sup, &QPushButton::clicked, this, &GUIModel::sort_by_suprafata_gui);
	QObject::connect(btn_sort_by_tip_sup, &QPushButton::clicked, this, &GUIModel::sort_by_tip_suprafata_gui);
	QObject::connect(btn_search, &QPushButton::clicked, this, &GUIModel::search_gui);
	QObject::connect(btn_filtru_suprafata, &QPushButton::clicked, this, &GUIModel::filtru_suprafata_gui);
	QObject::connect(btn_filtru_tip, &QPushButton::clicked, this, &GUIModel::filtru_tip_gui);
	QObject::connect(btn_report, &QPushButton::clicked, this, &GUIModel::raport_gui);
	QObject::connect(btn_undo, &QPushButton::clicked, this, &GUIModel::undo_gui);
	//QObject::connect(btn_cos, &QPushButton::clicked, [&]() {cos->show();});

	//pt cos
	QObject::connect(btn_add_cos, &QPushButton::clicked, this, &GUIModel::add_cos);
	QObject::connect(btn_remove_cos, &QPushButton::clicked, this, &GUIModel::remove_cos);
	QObject::connect(btn_genereaza_cos, &QPushButton::clicked, this, &GUIModel::genereaza_ap_cos);
	QObject::connect(btn_goleste_cos, &QPushButton::clicked, this, &GUIModel::goleste_cos);
	QObject::connect(btn_cos, &QPushButton::clicked, this, [&]() {auto cos = new CosGUI{ serv }; cos->show();});
	QObject::connect(btn_cos_desenare, &QPushButton::clicked, this, [&]() {auto cos = new CosDesenareGUI{ serv };cos->show();});
}

void GUIModel::get_info()
{
	
}

void GUIModel::get_info_tabel()
{
	
}

void GUIModel::add_gui()
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

void GUIModel::update_gui()
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

void GUIModel::remove_gui()
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

void GUIModel::search_gui()
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

void GUIModel::sort_by_nume_qui()
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

void GUIModel::sort_by_suprafata_gui()
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

void GUIModel::sort_by_tip_suprafata_gui()
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

void GUIModel::filtru_suprafata_gui()
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

void GUIModel::filtru_tip_gui()
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

void GUIModel::raport_gui()
{
	/*list->clear();
	std::map<string, int> my_map = serv.raport();
	for (auto it = my_map.begin(); it != my_map.end(); it++)
		list->addItem(QString::fromStdString(it->first) + ": " + QString::number(it->second));*/
}

void GUIModel::undo_gui()
{
	try {
		serv.undo();
		load_date(serv.get_lista_ap());
	}
	catch (const ServiceException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUIModel::add_cos()
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

void GUIModel::remove_cos()
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

void GUIModel::genereaza_ap_cos()
{
	try {
		serv.random_ap_existent(txt_genereaza_cos->text().toInt());
	}
	catch (const ServiceException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUIModel::goleste_cos()
{
	serv.goleste_cos();
}

void GUIModel::update()
{
	load_date(serv.get_lista_ap());
}
