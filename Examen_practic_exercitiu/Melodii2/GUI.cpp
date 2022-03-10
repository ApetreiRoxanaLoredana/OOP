#include "GUI.h"

void GUI::load_data(const vector<Melodie>& lista_mel)
{
	model->set_mel(lista_mel);
	repaint();
}

void GUI::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);

	ly_main->addWidget(tabel);

	QVBoxLayout* ly2 = new QVBoxLayout;
	ly2->addWidget(txt_titlu);
	slider->setMaximum(10);
	slider->setOrientation(Qt::Horizontal);
	ly2->addWidget(slider);
	ly2->addWidget(btn_update);
	ly2->addWidget(btn_remove);

	ly_main->addLayout(ly2);
}

void GUI::init_connection()
{
	QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		auto sel_item = tabel->selectionModel()->selectedIndexes();
		if (sel_item.isEmpty())
		{
			txt_titlu->setText("");
			slider->setValue(0);
			return;
		}

		int row = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto cel0 = tabel->model()->index(row, 0);
		int id = tabel->model()->data(cel0, Qt::UserRole).toInt();
		auto mel = serv.search(id);
		txt_titlu->setText(QString::fromStdString(mel.get_titlu()));
		slider->setValue(mel.get_rank());

		});
	QObject::connect(btn_update, &QPushButton::clicked, this, &GUI::update);
	QObject::connect(btn_remove, &QPushButton::clicked, this, &GUI::remove);
}

void GUI::update()
{
	auto sel_item = tabel->selectionModel()->selectedIndexes();
	if (!sel_item.isEmpty())
	{
		int row = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto cel0 = tabel->model()->index(row, 0);
		int id = tabel->model()->data(cel0, Qt::UserRole).toInt();
		auto mel = serv.search(id);
		string titlu = txt_titlu->text().toStdString();
		string artist = mel.get_artist();
		int rank = slider->value();

		serv.update(id, titlu, artist, rank);
		load_data(serv.get_lista_sort_rank());
	}
}

void GUI::remove()
{
	auto sel_item = tabel->selectionModel()->selectedIndexes();
	if (!sel_item.isEmpty())
	{
		int row = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto cel0 = tabel->model()->index(row, 0);
		int id = tabel->model()->data(cel0, Qt::UserRole).toInt();
		auto mel = serv.search(id);
		string artist = mel.get_artist();

		bool ok = false;
		for (const auto& m : serv.get_lista_sort_rank())
		{
			if (m.get_id() != mel.get_id() && m.get_artist() == mel.get_artist())
			{
				serv.remove(id);
				ok = true;
				load_data(serv.get_lista_sort_rank());
				break;
			}
		}

		if (!ok)
			QMessageBox::warning(nullptr, "warning", "e ultima melodie a acestui artist");
	}
}

void GUI::paintEvent(QPaintEvent*)
{
	QPainter p{ this };
	vector<int> rank(11, 0);
	for (const auto& m : serv.get_lista_sort_rank())
		rank.at(m.get_rank())++;

	int i = 10;
	for (const auto& k : rank)
	{
		int x = this->rect().bottomLeft().x();
		int y = this->rect().bottomLeft().y();

		p.drawLine(x + 300 + i, y, x + 300 + i, y - k * 20);
		i += 10;
	}

}
