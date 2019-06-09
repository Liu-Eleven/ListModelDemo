#include "custommodel.h"
#include <QDebug>

CustomModel::CustomModel(QObject *parent) : QAbstractListModel(parent)
{
    this->initialize();
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    // model有多少行，给view用的，固定写法
    return dataList.size();
}

QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    // view 通过行号和 列号，来获取对应的数据
    if (index.row() < 0 || index.row() >= dataList.size()) {
        return QVariant();
    }

    const CustomModelData &data = dataList.at(index.row());

    switch (role) {
    case ageRole: return data.age;
    case nameRole: return data.name;
    case addressRole: return data.address;
    case sexRole: {
        // 可以在这里做显示数据和存储的转换，如果有需要的话
        switch (data.sex) {
        case 0: return QString("男");
        case 1: return QString("女");
        case 2: return QString("保密");
        default: return QString("保密");
        }
    }
    default: return QVariant();
    }
}

QHash<int, QByteArray> CustomModel::roleNames() const
{
    // 基本也是这样的写法，不需要怎么改
    static QHash<int, QByteArray> names;
    if (0 == names.size()) {
        names.insert(ageRole, "age");
        names.insert(nameRole, "name");
        names.insert(addressRole, "address");
        names.insert(sexRole, "sex");
    }

    return names;
}

void CustomModel::initialize()
{
    // 这一句很重要，会发出信号告诉 view ，要开始重置数据了，请做好准备刷新界面
    beginResetModel();

    // 添数据，可以是从数据库中查出来的，从文件中加载的...等等
    for (int i = 0; i < 10; i ++) {
        CustomModelData data;
        data.age = (20+i);
        data.name = QString("名字%1").arg(i);
        data.address = QString("地址%1").arg(i);
        data.sex = i % 3;

        dataList.append(data);
    }

    // 重置完了，刷新界面吧
    endResetModel();

    return;
}

void CustomModel::append()
{
    CustomModelData data;
    data.age = (99);
    data.name = QString("add 名字");
    data.address = QString("add 地址");
    data.sex = 0;

    //
    beginInsertRows(QModelIndex(), dataList.size(), dataList.size());
    dataList.append(data);
    endInsertRows();
}
