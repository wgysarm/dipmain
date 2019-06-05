#ifndef IVFDTCPSOCKET_H
#define IVFDTCPSOCKET_H
/*
 * ----------------------------------------
 * | 8 byte length | 1 byte type |  data                      |
 * ----------------------------------------
 * 对数据进行了简单的封包，前面8byte表示后面数据的长度，读取，写入时全按这格式进行；
*/
#include <QObject>
#include <QTcpSocket>

class IVFDTcpSocket : public QTcpSocket
{
public:
    explicit IVFDTcpSocket(qintptr socketDescriptor, QObject *parent = 0);
    ~IVFDTcpSocket();

private:
    qintptr socketID;//保存id，

signals:

public slots:
    void sendData(QString data, const int); //发送数据（进行了简单的封包）
    void disConnectTcp(int id);             //断开连接
};

#endif // IVFDTCPSOCKET_H
