#pragma once

#include <QtWidgets>
#include <QUdpSocket>
#include <QTextEdit>


class udpServer: public QTextEdit{
Q_OBJECT
public:
    udpServer(QWidget* pwgt = 0);
private:
    QUdpSocket* pUdp;
public slots:
    void    slotSendDatagram();
};
