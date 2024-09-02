#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#include <QObject>
#include <QDateTime>



class TestItem
{
    //Q_OBJECT

public:

    TestItem(int sn,int m_env_sn,int m_type_sn,int m_type_cnt,QDateTime start_time);
    ~TestItem();

private:
    int m_sn;
    int m_env_sn;
    int m_type_sn;
    int m_type_cnt;
    QDateTime m_start_time;
};
#endif
