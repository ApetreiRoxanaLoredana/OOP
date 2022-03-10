#pragma once
#include "domain.h"
#include "service.h"
#include <vector>
#include <string>
#include <QAbstractTableModel>
using std::vector;
using std::string;

class My_table_model: public QAbstractTableModel
{
private:
	vector<Melodie> lista_mel;
public:
	My_table_model(vector<Melodie> lista_mel) :lista_mel{ lista_mel } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		parent.row();
		return (int)lista_mel.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		parent.column();
		return 6;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole)
		{
			auto mel = lista_mel[index.row()];
			if (index.column() == 0)
				return QString::number(mel.get_id());
			if (index.column() == 1)
				return QString::fromStdString(mel.get_titlu());
			if (index.column() == 2)
				return QString::fromStdString(mel.get_artist());
			if (index.column() == 3)
				return QString::fromStdString(mel.get_gen());
			if (index.column() == 4)
				return QString::number(get_nr_autor(mel.get_artist()));
			if (index.column() == 5)
				return QString::number(get_nr_gen(mel.get_gen()));

		}
		if (role == Qt::UserRole)
		{
			auto mel = lista_mel[index.row()];
			return QString::number(mel.get_id());
		}

		return QVariant();
	}

	void set_mels(const vector<Melodie>& mels) {
		this->lista_mel = mels;
		emit layoutChanged();
	}

	int get_nr_gen(string gen) const {
		int cnt = 0;
		for (const auto& mel : lista_mel)
			if (gen == mel.get_gen())
				cnt++;
		return cnt;
	}

	int get_nr_autor(string autor) const {
		int cnt = 0;
		for (const auto& mel : lista_mel)
			if (autor == mel.get_artist())
				cnt++;
		return cnt;
	}
};

