#include "udpServer.h"

udpServer::udpServer(QWidget* pwgt): QTextEdit(pwgt){
    setWindowTitle("UDP Server");

    pUdp = new QUdpSocket(this);

    QTimer* ptimer = new QTimer(this);
    ptimer->setInterval(500);
    ptimer->start();
    connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}

void udpServer::slotSendDatagram(){
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);

    QDateTime dt = QDateTime::currentDateTime();
    append(dt.toString());
    out << dt;
    pUdp->writeDatagram(ba, QHostAddress::LocalHost, 8080);
}
