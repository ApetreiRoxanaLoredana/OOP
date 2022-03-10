#include "MyTableModel.h"

int MyTableModel::rowCount(const QModelIndex& parent) const
{
    parent.row();
    return (int)lista.size();
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
    parent.column();
    return 5;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        auto joc = lista[index.row()];
        if (index.column() == 0)
            return QString::number(joc.get_id());
        if (index.column() == 1)
            return QString::number(joc.get_dim());
        if (index.column() == 2)
            return QString::fromStdString(joc.get_tabla());
        if (index.column() == 3)
            return QString::fromStdString(joc.get_jucator());
        if (index.column() == 4)
            return QString::fromStdString(joc.get_stare());
    }

    if (role == Qt::UserRole)
    {
        auto joc = lista[index.row()];
        return joc.get_id();
    }
    return QVariant();
}

void MyTableModel::set_lista(const vector<Joc>& lista_joc)
{
    this->lista = lista_joc;
    emit layoutChanged();
}
