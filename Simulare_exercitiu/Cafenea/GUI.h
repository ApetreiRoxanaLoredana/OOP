#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qlineedit.h>

class GUI: public QWidget
{
private:
	Service& serv;
	QListWidget* list = new QListWidget;
	QLineEdit* txt_nume = new QLineEdit;
	QLineEdit* txt_tara = new QLineEdit;
	QLineEdit* txt_pret = new QLineEdit;
	QPushButton* btn_sort = new QPushButton("Sorteaza");
	QPushButton* btn_filtru = new QPushButton("Filtreaza");

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="serv">Service</param>
	GUI(Service& serv) :serv{ serv } {
		
		init_comp();
		init_connection();
		load_data(serv.get_lista());
	};

	/// <summary>
	/// Aranjeaza componentele ferestrei principale
	/// </summary>
	void init_comp();

	/// <summary>
	/// Initializeaza conexiunile elementelor
	/// </summary>
	void init_connection();

	/// <summary>
	/// Incarca elementele din lista in lista din fereastra
	/// </summary>
	/// <param name="lista_cof"></param>
	void load_data(const vector<Coffee>& lista_cof);

	/// <summary>
	/// Filtreaza lista dupa numele tarii si pretul cafelei
	/// </summary>
	void filtru();

	/// <summary>
	/// Sorteaza lista dupa tara ei si pret
	/// </summary>
	void sortare();

	/// <summary>
	/// Afiseaza elementul selectat
	/// </summary>
	void get_info();

	/// <summary>
	/// Reface culorile elementelor filtrate
	/// </summary>
	void curata_culoare();

};

