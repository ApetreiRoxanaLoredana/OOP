#include "MyModel.h"

int MyModel::rowCount(const QModelIndex& parent) const
{
    parent.row();
    return (int)lista.size();
}

int MyModel::columnCount(const QModelIndex& parent) const
{
    parent.column();
    return 5;
}

QVariant MyModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        auto mel = lista[index.row()];
        if (index.column() == 0)
            return QString::number(mel.get_id());
        if (index.column() == 1)
            return QString::fromStdString(mel.get_titlu());
        if (index.column() == 2)
            return QString::fromStdString(mel.get_artist());
        if (index.column() == 3)
            return QString::number(mel.get_rank());
        if (index.column() == 4)
            return QString::number(get_nr_rank(mel.get_rank()));
    }

    if (role == Qt::UserRole)
    {
        auto mel = lista[index.row()];
        return QString::number(mel.get_id());
    }
    return QVariant();
}

int MyModel::get_nr_rank(int rank) const
{
    int cnt = 0;
    for (const auto& m : lista)
        if (m.get_rank() == rank)
            cnt++;
    return cnt;
}

void MyModel::set_mel(const vector<Melodie>& lista_mel)
{
    this->lista = lista_mel;
    emit layoutChanged();
}
