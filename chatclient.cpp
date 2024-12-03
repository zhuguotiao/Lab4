#include "chatclient.h"
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>

ChatClient::ChatClient(QObject *parent) :QObject(parent)
{

}

void ChatClient::onReadyRead()
{

}

void ChatClient::sendMessage(const QString &text, const QString &type)
{
    if(m_clientSocket->state()!=QAbstractSocket::ConnectedState)
        return;
    if(!text.isEmpty()){
        QDataStream serverStream(m_clientSocket);
        serverStream.setVersion(QDataStream::Qt_5_12);

        QJsonObject message;
        message["type"]=type;
        message["text"]=text;

        serverStream << QJsonDocument(message).toJson();
    }
}

void ChatClient::connectToServer(const QHostAddress &address, quint16 port)
{
   m_clientSocket->connectToHost()
}
