
#include "test_env.h"

TestEnv::TestEnv(int sn,int dev_sn,double temp,double humidity,double press_env,
                 QString probe_batch,QString probe_sn,QString stand_dev,QString tester)
{

    m_sn = sn;
    m_dev_sn = dev_sn;
    m_temp = temp;
    m_humidity = humidity;
    m_press_env = press_env;
    m_probe_batch = probe_batch;
    m_probe_sn = probe_sn;
    m_stand_dev = stand_dev;
    m_tester = tester;
}

TestEnv::~TestEnv()
{

}


