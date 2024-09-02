
#include "test_item.h"

TestItem::TestItem(int sn,int env_sn,int type_sn,int type_cnt,QDateTime start_time)
{
    m_sn = sn;
    m_env_sn = env_sn;
    m_type_sn = type_sn;
    m_type_cnt = type_cnt;
    m_start_time = start_time;
}

TestItem::~TestItem()
{

}


