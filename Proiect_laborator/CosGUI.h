#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qcombobox.h>
#include <vector>
#include "Cos.h"
#include "Domain.h"
#include "Service.h"
#include "Observer.h"

class CosGUI : public QWidget, public Observer
{
private:

	Service& serv;
	QListWidget* list_cos = new QListWidget;
	QPushButton* btn_exit = new QPushButton("Exit");
	QPushButton* btn_goleste = new QPushButton("Goleste");
	QPushButton* btn_random = new QPushButton("Adauga apartamente random");
	QPushButton* btn_add = new QPushButton("Adauga apartament existent");
	QPushButton* btn_export = new QPushButton("Exporta");
	QLineEdit* txt_random = new QLineEdit;
	QLineEdit* txt_ap = new QLineEdit;
	QLineEdit* txt_export = new QLineEdit;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="serv"></param>
	CosGUI(Service& serv) : serv{ serv } {
		serv.add_observer(this);
		init_GUI_comp();
		init_connect();
		load_data(serv.get_cos());
	}

	/// <summary>
	/// Aranjeaza componentele aplicatiei in fereastra
	/// </summary>
	void init_GUI_comp();

	/// <summary>
	/// Incarca datele in fereastra
	/// </summary>
	/// <param name="list_ap"></param>
	void load_data(const std::vector<Apartament>& list_ap);

	/// <summary>
	/// Initializeaza conexiunile dintre componenetele ferestrei si actiuni
	/// </summary>
	void init_connect();

	/// <summary>
	/// Goleste lista de apartamente
	/// </summary>
	void goleste_gui();

	/// <summary>
	/// Adauga random apartamente
	/// </summary>
	void add_random_qui();

	/// <summary>
	/// Adauga un apartament existent
	/// </summary>
	void add_gui();

	/// <summary>
	/// Exporta intr-un fisier csv apartamentele din lista
	/// </summary>
	void export_gui();

	void update() override;

	~CosGUI() {
		serv.remove_observer(this);
	}
};

