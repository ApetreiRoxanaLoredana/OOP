#pragma once
#include <qabstracttablemodel>
#include "Domain.h"
#include <vector>
using std::vector;

class MyTableModel: public QAbstractTableModel
{
private:
	vector<Joc> lista;

public:
	MyTableModel(const vector<Joc>& lista) : lista{ lista } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	void set_lista(const vector<Joc>& lista);
};

