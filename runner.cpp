#include "runner.h"

Runner::Runner( QObject *parent) : QObject(parent)
{
this->str=str;



    m_running=true;
}

bool Runner::running() const
{

}
void Runner::run()
{
    count = 0;
    qDebug()<<"RUN "<<str;
    // Переменная m_running отвечает за работу объекта в потоке.
    // При значении false работа завершается
    while (m_running)
    {
        if(count<100000000){
        count++;
        }else{
                 qDebug()<<str;
            count=0;
        }
  //      emit sendMessage(m_message); // Высылаем данные, которые будут передаваться в другой поток
  //      qDebug() << m_message << " " << m_message_2 << " " << count;

    }
    qDebug()<<"finished "<<str;
    emit finished();
}


void Runner::setRunning(bool running)
{
    if (m_running == running){
        return;
    }
    m_running = running;

    emit runningChanged(running);
}
