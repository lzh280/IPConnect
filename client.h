#ifndef CLIENT_H
#define CLIENT_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();


    const QTcpSocket *getSocket();

    void setClientUsername(const QString);
    void sendDetail();
    void sendMessage(QString);
    void setSocket(QTcpSocket *t_socket);
    void setUsername(const QString);

    QTcpSocket *m_socket;

protected:
    QString m_ClientUsername;
    QString m_MyUsername;
    bool m_detailAccepted;
    bool m_detailSent;
    QMap<QString, QString> m_request;
    QMap<QString, QString> m_response;

private:
    void processRead(QByteArray);
    void handleRequest();

signals:
    void capturedDetail(QString, Client*);
    void destroyingConnection(QString);
    void gotMessageRequest(QString);
    void warning(QString,QString);

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void bytesWritten(qint64 bytes);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void error(QAbstractSocket::SocketError socketError);
};

#endif // CLIENT_H
