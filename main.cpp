#include "udpServer.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    udpServer server;
    server.show();

    return app.exec();
}
