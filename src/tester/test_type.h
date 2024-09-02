#ifndef TEST_TYPE_H
#define TEST_TYPE_H

#include <QObject>



class TestType
{
    //Q_OBJECT

public:

    TestType(int sn,QString type);
    ~TestType();

private:
    int m_sn;
    QString m_type;
};
#endif // MAINWINDOW_H
