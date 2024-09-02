#ifndef TEST_DEV_DATA_H
#define TEST_DEV_DATA_H

#include <QObject>



class TestItemData
{
    //Q_OBJECT

public:

    TestItemData(int sn,double vol,double flow,double flow_stander);
    ~TestItemData();

private:
    int m_sn;
    double m_vol;
    double m_flow;
    double m_flow_stander;
};
#endif // MAINWINDOW_H
