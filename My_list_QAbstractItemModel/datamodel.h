#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include <QStringList>

class DataModel : public QAbstractItemModel
{
    Q_OBJECT

    QStringList my_data;

public:
    explicit DataModel(QObject *parent = nullptr);

    //Model interface implementation
    virtual int columnCount(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex & = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QModelIndex index(int row, int column,const QModelIndex & = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &child) const;

public slots:
    void add_value(const QString &value);
    void delete_value(int id);
};

#endif // DATAMODEL_H
