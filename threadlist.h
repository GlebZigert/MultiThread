#ifndef THREADLIST_H
#define THREADLIST_H

#include <QObject>
#include <QMap>
#include <mythread.h>

class threadList : public QObject
{
    Q_OBJECT
public:
    explicit threadList(QObject *parent = nullptr);

    QMap<QString, MyThread* > list;

    void append(QString);

    void remove(QString str);

signals:

};

#endif // THREADLIST_H
