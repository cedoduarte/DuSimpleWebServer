#include "DuWebServer.h"
#include <QTcpSocket>
#include <QFile>
#include <QTextStream>

DuWebServer::DuWebServer(QObject *parent)
    : QTcpServer(parent)
{
    mSocket = nullptr;
}

bool DuWebServer::startWebServer(int port)
{
    return listen(QHostAddress::Any, port);
}

void DuWebServer::incomingConnection(qintptr handle)
{
    mSocket = new QTcpSocket(this);
    mSocket->setSocketDescriptor(handle);
    QFile file(":/index.html");
    if (!file.open(QIODevice::Text | QIODevice::ReadOnly)) {
        emit fileErrorHasOccurred(file.errorString());
        return;
    }
    QTextStream xin(&file);
    mSocket->write(xin.readAll().toLatin1());
    file.close();
}

