#include "GUI.h"



void GUI::load_data(const vector<Melodie>& lista_mel)
{
	model->set_mels(lista_mel);
	repaint();
}

void GUI::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);

	ly_main->addWidget(tabel);

	QFormLayout* ly_form = new QFormLayout;
	ly_form->addRow("Titlu: ", txt_titlu);
	ly_form->addRow("Artist: ", txt_artist);
	ly_form->addRow("Gen: ", txt_gen);
	ly_form->addWidget(btn_add);
	ly_form->addWidget(btn_remove);

	ly_main->addLayout(ly_form);
}

void GUI::init_conection()
{
	QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		if (tabel->selectionModel()->selectedIndexes().isEmpty())
		{
			txt_titlu->setText("");
			txt_artist->setText("");
			txt_gen->setText("");
			return;
		}
		int selRow = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto cel0 = tabel->model()->index(selRow, 0);
		auto id = tabel->model()->data(cel0, Qt::UserRole).toString();
		auto mel = serv.search(id.toInt());
		txt_titlu->setText(QString::fromStdString(mel.get_titlu()));
		txt_artist->setText(QString::fromStdString(mel.get_artist()));
		txt_gen->setText(QString::fromStdString(mel.get_gen()));

		});
	QObject::connect(btn_add, &QPushButton::clicked, this, &GUI::add);
	QObject::connect(btn_remove, &QPushButton::clicked, this, &GUI::remove);
}

void GUI::add()
{
	string titlu = txt_titlu->text().toStdString();
	string artist = txt_artist->text().toStdString();
	string gen = txt_gen->text().toStdString();
	serv.add(titlu, artist, gen);
	load_data(serv.get_lista_sort_autor());
}

void GUI::remove()
{
	int selRow = tabel->selectionModel()->selectedIndexes().at(0).row();
	auto cel0 = tabel->model()->index(selRow, 0);
	auto id = tabel->model()->data(cel0, Qt::UserRole).toInt();
	serv.remove(id);
	load_data(serv.get_lista_sort_autor());
	
}

void GUI::paintEvent(QPaintEvent*)
{
	QPainter p{ this };
	int pop = 10, rock = 10, folk = 10, disco = 10;
	for (const auto& mel : serv.get_lista_sort_autor())
	{
		if (mel.get_gen() == "pop")
		{
			QPoint centru;
			centru.setX(this->rect().topLeft().x());
			centru.setY(this->rect().topLeft().y());
			p.drawEllipse(centru, pop, pop);
			pop += 20;
		}

		if (mel.get_gen() == "rock")
		{
			QPoint centru;
			centru.setX(this->rect().topRight().x());
			centru.setY(this->rect().topRight().y());
			p.drawEllipse(centru, rock, rock);
			rock += 20;
		}

		if (mel.get_gen() == "folk")
		{
			QPoint centru;
			centru.setX(this->rect().bottomLeft().x());
			centru.setY(this->rect().bottomLeft().y());
			p.drawEllipse(centru, folk, folk);
			folk += 20;
		}

		if (mel.get_gen() == "disco")
		{
			QPoint centru;
			centru.setX(this->rect().bottomRight().x());
			centru.setY(this->rect().bottomRight().y());
			p.drawEllipse(centru, disco, disco);
			disco += 20;
		}
	}
}
