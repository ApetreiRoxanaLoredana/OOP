#include "GUI.h"

void GUI::load_data(const vector<Joc>& lista_joc)
{
	model->set_lista(lista_joc);
}

void GUI::init_comp()
{
	setLayout(ly_main);
	ly_main->addWidget(tabel);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Dimeniunea: ", txt_dim);
	ly_form->addRow("Tabla: ", txt_tabla);
	ly_form->addRow("Jucator: ", txt_jucator);
	ly_form->addWidget(btn_add);

	ly_form->addRow("Id: ", txt_id2);
	ly_form->addRow("Dimensiune: ", txt_dim2);
	ly_form->addRow("Tabla: ", txt_tabla2);
	ly_form->addRow("Jucator: ", txt_jucator2);
	ly_form->addRow("Stare: ", txt_stare2);
	ly_form->addWidget(btn_modifica);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			ly[i]->addWidget(butoane[i][j]);
			butoane[i][j]->hide();
		}

		ly_tabla->addLayout(ly[i]);
	}


	ly_main->addLayout(ly_form);
	ly_main->addLayout(ly_tabla);
}

void GUI::init_connection()
{
	QObject::connect(btn_add, &QPushButton::clicked, this, &GUI::add);
	QObject::connect(btn_modifica, &QPushButton::clicked, this, &GUI::update);
	QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		auto sel = tabel->selectionModel()->selectedIndexes();
		if (sel.isEmpty())
		{
			txt_dim->setText("");
			txt_dim2->setText("");
			txt_jucator->setText("");
			txt_jucator2->setText("");
			txt_tabla->setText("");
			txt_tabla2->setText("");
			txt_id2->setText("");
			txt_stare2->setText("");
			return;
		}

		int row = sel.at(0).row();
		auto cel0 = tabel->model()->index(row, 0);
		int id = tabel->model()->data(cel0, Qt::UserRole).toInt();
		auto joc = serv.search(id);

		txt_dim->setText(QString::number(joc.get_dim()));
		txt_dim2->setText(QString::number(joc.get_dim()));
		txt_jucator->setText(QString::fromStdString(joc.get_jucator()));
		txt_jucator2->setText(QString::fromStdString(joc.get_jucator()));
		txt_tabla->setText(QString::fromStdString(joc.get_tabla()));
		txt_tabla2->setText(QString::fromStdString(joc.get_tabla()));
		txt_id2->setText(QString::number(id));
		txt_stare2->setText(QString::fromStdString(joc.get_stare()));

		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				butoane[i][j]->hide();
			
		for (int i = 0; i < joc.get_dim(); i++)
		{
			for (int j = 0; j < joc.get_dim(); j++)
			{
				butoane[i][j]->setHidden(false);
				butoane[i][j]->setText(QString(joc.get_tabla().at(i * joc.get_dim() + j)));
			}
		}
	});
	
	for(int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			QObject::connect(butoane[i][j], &QPushButton::clicked, this, [this, i, j]() {
				joaca(i, j);
				});
		}
}

void GUI::add()
{
	try {

		serv.add(txt_dim->text().toInt(), txt_tabla->text().toStdString(), txt_jucator->text().toStdString());
		load_data(serv.get_lista_sort_stare());
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::update()
{
	try {

		serv.update(txt_id2->text().toInt(), txt_dim2->text().toInt(), txt_tabla2->text().toStdString(), txt_jucator2->text().toStdString(), txt_stare2->text().toStdString());
		load_data(serv.get_lista_sort_stare());
	}
	catch (const ValidatorException& ex) {
		QMessageBox::warning(nullptr, "warning", QString::fromStdString(ex.get_message()));
	}
}

void GUI::joaca(int i, int j)
{
	if (butoane[i][j]->text() != "-")
		QMessageBox::warning(nullptr, "warning", "Poti selecta doar pe -");
	else
	{
		int id = txt_id2->text().toInt();
		auto joc = serv.search(id);
		string jucator;
		if (joc.get_jucator() == "X")
			jucator = "O";
		else
			jucator = "X";
		butoane[i][j]->setText(QString::fromStdString(joc.get_jucator()));
		string tabla = joc.get_tabla();
		tabla.at(i * joc.get_dim() + j) = jucator.at(0);
		serv.update(id, joc.get_dim(), tabla, jucator, joc.get_stare());
		load_data(serv.get_lista_sort_stare());
	}
				
}





