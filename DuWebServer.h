#ifndef DUWEBSERVER_H
#define DUWEBSERVER_H

#include <QTcpServer>

class DuWebServer : public QTcpServer
{
    Q_OBJECT
public:
    DuWebServer(QObject *parent = nullptr);
    bool startWebServer(int port);
signals:
    void fileErrorHasOccurred(QString);
protected:
    void incomingConnection(qintptr handle);
private:
    QTcpSocket *mSocket;
};

#endif // DUWEBSERVER_H
