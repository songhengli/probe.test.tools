#ifndef TEST_DEV_H
#define TEST_DEV_H

#include <QObject>



class TestDev
{
    //Q_OBJECT

public:

    TestDev(int sn,QString hw_ver,QString sw_ver,QString coder);
    ~TestDev();

private:
    int m_sn;
    QString m_hw_ver;
    QString m_sw_ver;
    QString m_coder;
};
#endif // MAINWINDOW_H
