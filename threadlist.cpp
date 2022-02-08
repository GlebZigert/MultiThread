#include "threadlist.h"

threadList::threadList(QObject *parent) : QObject(parent)
{

}

void threadList::append(QString str)
{
    if(str!=0){
         MyThread*  mm=new MyThread(str);
        //list.append(str);
        list.insert(str,mm);
    }
}

void threadList::remove(QString str)
{
MyThread* current= list.value(str);
    current->stop();
    list.remove(str);


}
