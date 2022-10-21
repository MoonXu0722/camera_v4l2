#include "camera.h"

camera::camera(QObject *parent) : QObject(parent)
{
#ifdef _WIN32
    WORD wVersionRequested;
       WSADATA wsaData;
       int err;
       wVersionRequested = MAKEWORD(2,2);
       err = WSAStartup( wVersionRequested, &wsaData );
       if ( err != 0 ) {
           return;
       }
       if ( LOBYTE( wsaData.wVersion ) != 2 ||
            HIBYTE( wsaData.wVersion ) != 2 ) {
           WSACleanup();
           return;
       }
#endif
    socket.bind(QHostAddress("192.168.1.162"), 8000);

    connect(&socket, SIGNAL(readyRead()),
            this, SLOT(readImage()));
}


void camera::readImage()
{
    while (socket.hasPendingDatagrams()) {
             datagram = socket.receiveDatagram();
             qDebug() << datagram.data();
             unsigned char spos[3] = {(unsigned char)0xff, (unsigned char)0xd8};
             unsigned char epos[3] = {(unsigned char)0xff, (unsigned char)0xd9};
             int startpos = datagram.data().indexOf((char *)spos, 0);
             if(startpos == -1)
             {
                 datagram.data().clear();
                 return;
             }
             int endpos = datagram.data().indexOf((char *)epos, startpos);
             if(endpos == -1)
             {
                 return;
             }
             QByteArray imageBuffer = datagram.data().mid(startpos, endpos-startpos+2);
             image.loadFromData(imageBuffer, "JPEG");

             emit newImageReady(image);

             datagram.data().clear();
         }
}
