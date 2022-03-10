#pragma once
#include "Service.h"
#include "Exception.h"
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qlistwidget.h>

class GUI : public QWidget
{
private:
	Service& serv;
	QListWidget* lista = new QListWidget();
	QLineEdit* txt_pret_total = new QLineEdit;
	QLineEdit* txt_count = new QLineEdit;
	QPushButton* btn_inc = new QPushButton("inc");

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="serv">Service</param>
	GUI(Service& serv) : serv{ serv } {

		init_comp_gui();
		load_data(serv.sortare());
		init_connection();
	};

	/// <summary>
	/// Incarca datele din lista de produse in lista din interfata utilizator
	/// </summary>
	/// <param name="lista">lista de produse</param>
	void load_data(const vector<Produs>& lista);

	/// <summary>
	/// Initializeaza componentele interfatei
	/// </summary>
	void init_comp_gui();

	/// <summary>
	/// Initializeaza conexiunile cu componentele interfatei
	/// </summary>
	void init_connection();

	/// <summary>
	/// Modifica produsul care are id ul selectat in lista din interfata
	/// </summary>
	void update();

};

