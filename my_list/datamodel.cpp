#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QAbstractItemModel{parent}
{


}

int DataModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

int DataModel::rowCount(const QModelIndex &) const
{
    return my_data.size();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if ( role == Qt::DisplayRole)
    {
        return my_data.at(index.row());
    }
    return QVariant();
}

QModelIndex DataModel::index(int row, int column, const QModelIndex &) const
{
    return createIndex(row,column, (void*)&my_data.at(row));
}

QModelIndex DataModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

void DataModel::add_value(const QString &value)
{
    my_data.push_back(value);
    emit layoutChanged();
}

void DataModel::delete_value(int id)
{
    if (id<my_data.size())
    {
        my_data.erase(my_data.begin()+id,my_data.begin()+id+1);
        emit layoutChanged();
    }
}
