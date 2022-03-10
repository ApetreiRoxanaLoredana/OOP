#pragma once
#include "Domain.h"
#include <vector>
#include <qdebug.h>
#include <QAbstractTableModel> 
#include "Observer.h"

using std::vector;

class MyTableModel: public QAbstractTableModel
{
private:
	vector<Apartament> apartamente;

public:
	MyTableModel(const vector<Apartament>& aps) : apartamente{ aps } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		parent.row();
		return (int)apartamente.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		parent.row();
		return 3;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		//qDebug() << "row: " << index.row() << " column: " << index.column() << '\n';
		if (role == Qt::DisplayRole) {
			auto ap = apartamente[index.row()];
			if (index.column() == 0)
				return QString::fromStdString(ap.get_nume());
			if (index.column() == 1)
				return QString::number(ap.get_suprafata());
			if (index.column() == 2)
				return QString::fromStdString(ap.get_tip());
		}

		if (role == Qt::UserRole)
			return apartamente[index.row()].get_apartament();


		return QVariant{};
	}

	void set_aps(const vector<Apartament>& aps) {
		this->apartamente = aps;
		//QModelIndex topLeft = createIndex(0, 0);
		//QModelIndex bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
	}

};

