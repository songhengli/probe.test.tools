
#include "test_dev.h"

TestDev::TestDev(int sn,QString hw_ver,QString sw_ver,QString coder)
{
    m_sn = sn;
    m_hw_ver = hw_ver;
    m_sw_ver = sw_ver;
    m_coder = coder;

}

TestDev::~TestDev()
{

}


