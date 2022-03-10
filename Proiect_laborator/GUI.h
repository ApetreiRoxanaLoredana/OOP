#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qtablewidget.h>
#include "Service.h"
#include "CosGUI.h"
#include "Observer.h"
#include "CosDesenareGUI.h"

#define VA std::vector<Apartament>

class GUI : public QWidget, public Observer
{
private:
	Service& serv;
	QListWidget* list = new QListWidget();
	QPushButton* btn_sort_by_nume = new QPushButton("Sorteaza dupa nume");
	QPushButton* btn_sort_by_sup = new QPushButton("Sorteaza dupa suprafata");
	QPushButton* btn_sort_by_tip_sup = new QPushButton("Sorteaza dupa tip si suprafata");
	QPushButton* btn_add = new QPushButton("Adauga");
	QPushButton* btn_remove = new QPushButton("Sterge");
	QPushButton* btn_update = new QPushButton("Modifica");
	QPushButton* btn_search = new QPushButton("Cauta");
	QPushButton* btn_filtru_tip = new QPushButton("Filtreaza dupa tip");
	QPushButton* btn_filtru_suprafata = new QPushButton("Filtreaza dupa suprafata");
	QPushButton* btn_exit = new QPushButton("Exit");
	QLineEdit* txt_numar = new QLineEdit;
	QLineEdit* txt_nume = new QLineEdit;
	QLineEdit* txt_suprafata = new QLineEdit;
	QLineEdit* txt_tip = new QLineEdit;
	QComboBox* combo_reverse = new QComboBox;
	QComboBox* combo_reverse2 = new QComboBox;
	QLineEdit* txt_suprafata_filtru = new QLineEdit;
	QLineEdit* txt_tip_filtru = new QLineEdit;
	QPushButton* btn_report = new QPushButton("Raport");
	QPushButton* btn_undo = new QPushButton("Undo");
	QPushButton* btn_cos = new QPushButton("Cos");
	CosGUI* cos = new CosGUI{ serv };
	QPushButton* btn_add_cos = new QPushButton("Adauga in cos");
	QPushButton* btn_remove_cos = new QPushButton("Sterge din cos");
	QPushButton* btn_genereaza_cos = new QPushButton("Genereaza in cos");
	QPushButton* btn_goleste_cos = new QPushButton("Goleste din cos");
	QLineEdit* txt_id_cos = new QLineEdit;
	QLineEdit* txt_genereaza_cos = new QLineEdit;
	QTableWidget* tabel = new QTableWidget{0, 4};
	QPushButton* btn_cos_desenare = new QPushButton("Cos desenare");

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="serv"></param>
	GUI(Service& serv) : serv{ serv } {
		serv.add_observer(this);
		init_GUI_comp();
		set_color();
		load_date(serv.get_lista_ap());
		init_connect();
	}
	/// <summary>
	/// Aranjeaza componentele aplicatiei in fereastra
	/// </summary>
	void init_GUI_comp();

	/// <summary>
	/// Seteaza culoarile elementelor
	/// </summary>
	void set_color();

	/// <summary>
	/// Incarca datele din lista
	/// </summary>
	/// <param name="list_ap"></param>
	void load_date(const VA& list_ap);

	/// <summary>
	/// Conecteaza componentele aplicatiei cu actiuni
	/// </summary>
	void init_connect();

	/// <summary>
	/// Leaga lista de mai multe componente
	/// </summary>
	void get_info();

	void get_info_tabel();

	/// <summary>
	/// Adauga un apartament nou in lista
	/// </summary>
	void add_gui();

	/// <summary>
	/// Modifica un apartament din lista
	/// </summary>
	void update_gui();

	/// <summary>
	/// Sterge un apartament din lista
	/// </summary>
	void remove_gui();

	/// <summary>
	/// Cauta un apartament din lista
	/// </summary>
	void search_gui();

	/// <summary>
	/// Sorteaza lista crescator/descrescator dupa numele proprietarului
	/// </summary>
	void sort_by_nume_qui();

	/// <summary>
	/// Sorteaza lista crescator/descrescator dupa suprafata apartamentelor
	/// </summary>
	void sort_by_suprafata_gui();

	/// <summary>
	/// Sorteaza lista crescator/descrescator dupa tipul si suprafata apartamentului
	/// </summary>
	void sort_by_tip_suprafata_gui();

	/// <summary>
	/// Filtreaza lista dupa suprafata apartamentului
	/// </summary>
	void filtru_suprafata_gui();

	/// <summary>
	/// Filtreaza lista dupa tipul apartamentelor
	/// </summary>
	void filtru_tip_gui();

	/// <summary>
	/// Afiseaza cate apartamente de tipul respectiv sunt
	/// </summary>
	void raport_gui();

	/// <summary>
	/// Reface ultima operatie
	/// </summary>
	void undo_gui();

	/// <summary>
	/// Adauga un apartament in cos
	/// </summary>
	void add_cos();

	/// <summary>
	/// Sterge din cos un apartament
	/// </summary>
	void remove_cos();

	/// <summary>
	/// Genereaza in cos un numar de apartamente existeinte in lista
	/// </summary>
	void genereaza_ap_cos();

	/// <summary>
	/// Sterge toate apartamentele din cos
	/// </summary>
	void goleste_cos();

	/// <summary>
	/// Actualizeaza ferestrele
	/// </summary>
	void update() override;

	~GUI() {
		serv.remove_observer(this);
	}
};

