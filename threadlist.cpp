#include "threadlist.h"

threadList::threadList(QImage* img, QObject *parent) : QObject(parent)
{
this->img=img;
}

bool threadList::append(QString str)
{


    foreach(QString val, list.keys()){

       if(val==str){

           return false;


       }
    }

    foreach(MyThread* val, list.values()){

      val->stop();

    }


    qDebug("append");

    if(str!=0){
         MyThread*  mm=new MyThread(img,str);
       //  connect(mm->runner,&Runner::new_frame,this,receiveFrame());

        connect(&mm->runner,SIGNAL(new_frame()),this,SLOT(receiveFrame()));
        connect(&mm->runner,SIGNAL(lost_connection(QString)),this,SLOT(lost_connection(QString)));
        //list.append(str);
        list.insert(str,mm);

        mm->thread.start();
    }


    foreach(MyThread* val, list.values()){


qDebug()<<val->runner.URL<<" "<<val->runner.m_running<<" "<<val->runner.thread()->isFinished();

    }

    return true;
}

void threadList::remove(QString str)
{
MyThread* current= list.value(str);
    current->stop();
   // delete current;
   list.remove(str);

}

void threadList::receiveFrame()
{
  //  qDebug()<<"receiveFrame()";
    emit frame();


}

void threadList::lost_connection(QString URL)
{
     qDebug()<<" !!! !!! CONNECTION LOST";
  //   remove(URL);
  //   append(URL);


}
