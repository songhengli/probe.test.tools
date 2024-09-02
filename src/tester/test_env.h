#ifndef TEST_ENV_H
#define TEST_ENV_H

#include <QObject>



class TestEnv
{
    //Q_OBJECT

public:

    TestEnv(int sn,int test_dev,double temp,double humidity,double press_env,
            QString probe_batch,QString probe_sn,QString stand_dev,QString tester);
    ~TestEnv();

private:
    int m_sn;
    int m_dev_sn;
    double m_temp;
    double m_humidity;
    double m_press_env;
    QString m_probe_batch;
    QString m_probe_sn;
    QString m_stand_dev;
    QString m_tester;
};
#endif // MAINWINDOW_H
