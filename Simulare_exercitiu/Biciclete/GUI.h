#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtablewidget.h>

class GUI: public QWidget
{
private:
	Service& serv;
	QTableWidget* tabel = new QTableWidget;
	QPushButton* btn_sterge_max = new QPushButton("Sterge max");
	QPushButton* btn_sterge_tip = new QPushButton("Sterge tip");
	QLineEdit* txt_tip = new QLineEdit;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="serv">Service</param>
	GUI(Service& serv) :serv{ serv } {
		init_comp();
		load_data(serv.sorteaza());
		init_connection();
	};

	/// <summary>
	/// Nu permite copierea obiectului
	/// </summary>
	/// <param name="ot">GUI</param>
	GUI(const GUI& ot) = delete;

	/// <summary>
	/// Incarca informatile din lista de biciclete in tabel
	/// </summary>
	/// <param name="lista_bici">lista de biciclete</param>
	void load_data(const vector<Bicicleta>& lista_bici);

	/// <summary>
	/// Aranjeaza componentele ferestrei
	/// </summary>
	void init_comp();

	/// <summary>
	/// Conecteaza elementelel ferestrei cu actiuni
	/// </summary>
	void init_connection();

	/// <summary>
	/// Sterge toate bicicletele de tipul respectiv
	/// </summary>
	void sterge_tip();

	/// <summary>
	/// Sterge bicicletele care au pretul maxim
	/// </summary>
	void sterge_max();
};

