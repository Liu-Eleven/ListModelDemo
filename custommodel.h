#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractListModel>
#include <QVector>

class CustomModelData {
public:
    int     age;
    QString name;
    QString address;
    int     sex;
};

class CustomModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CustomModel(QObject *parent = nullptr);

    enum CustomRoles {
        // 这个也可以写别的，不过一般从 UserRole 后面开始写，具体原因可以看帮助的 Model/View Programming 章节
        // 然后顺序的话，和数据的顺序对应，命名就看自己喜好啦
        ageRole = Qt::UserRole + 1,
        nameRole,
        addressRole,
        sexRole
    };

    // 继承自 QAbstractListModel 必须要实现的三个虚函数
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

public slots:
    /**
     * @brief initialize 初始化model
     */
    void initialize();

    /**
     * @brief append 往 model 里添加数据，这里因为是测试，所以就不写类型了
     */
    void append();

private:
    QVector<CustomModelData> dataList;
};

#endif // CUSTOMMODEL_H
