#pragma once
#include <qabstracttablemodel>
#include <vector>
#include "Domain.h"
using std::vector;

class MyModel: public QAbstractTableModel
{
private:
	vector<Melodie> lista;
public:
	MyModel(const vector<Melodie>& lista) : lista{ lista } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	int get_nr_rank(int rank) const;

	void set_mel(const vector<Melodie>& lista_mel);
};

