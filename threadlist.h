#ifndef THREADLIST_H
#define THREADLIST_H

#include <QObject>
#include <QMap>
#include <mythread.h>

class threadList : public QObject
{
    Q_OBJECT
public:
    explicit threadList(QImage* img, QObject *parent = nullptr);

    QMap<QString, MyThread* > list;

    bool append(QString);

    void remove(QString str);

    QImage* img;



public slots:
    void receiveFrame();
    void lost_connection(QString URL);
signals:
    void frame();

};

#endif // THREADLIST_H
