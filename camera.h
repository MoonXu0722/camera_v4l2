#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QUdpSocket>
#include <QByteArray>
#include <QImage>
#include <QNetworkDatagram>
#include <winsock2.h>
class camera : public QObject
{
    Q_OBJECT
public:
    explicit camera(QObject *parent = nullptr);
public slots:
    void readImage();
signals:
    void newImageReady(QImage img);

private:
    QUdpSocket socket;
    //QByteArray imageArray;
    QNetworkDatagram datagram;
    QImage image;

signals:

};

#endif // CAMERA_H
