#include "mini_fereastra.h"
#include <qlayout.h>

void Mini_fereastra::init_comp()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(lbl);
}

void Mini_fereastra::update()
{
	int cnt = 0;
	for (const auto& p : serv.get_lista_sort_pret())
		if (p.get_tip() == tip)
			cnt++;
	lbl->setText("Produse = " + QString::number(cnt) + "                                           ");
}
