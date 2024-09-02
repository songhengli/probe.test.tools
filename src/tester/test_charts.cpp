
#include "test_charts.h"
#include <QDebug>

TestCharts::TestCharts()
{

    maxX = 1000;
    maxY = 130;
    cnt = 0;
    ruler_xs = 0;
    ruler_xe = 0;
    xs_xe = 0;
    ruler_move = false;
    timeout_flag = false;
    splineSeries = new QSplineSeries();
    splineSeriesRuler = new QSplineSeries();
    chart = new QChart();
    timer = new QTimer(this);
    timer->start(20);

    axisX = new QValueAxis();
    axisY = new QValueAxis();

    chart->legend()->hide();
    chart->setTitle("探头工装");
    chart->addSeries(splineSeries);
    chart->addSeries(splineSeriesRuler);

    axisY->setLabelFormat("%i");
    axisY->setTitleText("流量/L/min");
    chart->addAxis(axisY,Qt::AlignLeft);
    axisY->setRange(0,maxY);
    splineSeries->attachAxis(axisY);
    splineSeriesRuler->attachAxis(axisY);

    axisX->setLabelFormat("%i");
    axisX->setTitleText("占空比/%");
    chart->addAxis(axisX,Qt::AlignBottom);
    axisX->setRange(0,maxX);
    splineSeries->attachAxis(axisX);
    splineSeriesRuler->attachAxis(axisX);
    this->setRenderHint(QPainter::Antialiasing);
    this->setChart(chart);



    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));
}

void TestCharts::mouseDoubleClickEvent(QMouseEvent *event)
{
    for(int i=0;i<130;i++)
    {
        splineSeriesRuler->append(dataX.at(0),i);
    }
    //启动线程
}
void TestCharts::curveDraw(int x,int y)
{
    dataX.append(x);
    dataY.append(y);

   // this->splineSeries->append()
   // splineSeriesRuler->setVisible(true);

    for(int i=0;i<130;i++)
    {
        splineSeriesRuler->append(dataX.at(0),i);
    }


}

void TestCharts::curveDraw(QList<int> &x, QList<int> &y)
{
    dataX = x;
    dataY = y;

    for(int i=0;i<x.size();i++)
    {
        splineSeries->append(x.at(i),y.at(i));
    }
}
//记录10ms间隔的两个点
//以曲线0点为基准
//axisX的0点到chart的0点80个像素，终点是40个像素
//获取chart的size()的weight(),减去80+40，就是坐标轴的宽度，分割成1000分
//转换为绝对位置显示
//

void TestCharts::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){

            press_point = QCursor::pos();
            //5ms

            if(timeout_flag == true)
            {
                timeout_flag = false;
                ruler_xs = ruler_xe;
                ruler_xe = press_point.x();
                xs_xe = ruler_xe - ruler_xs;
                ruler_move = true;
            }


                    qDebug() << "TestCharts" << this->mapToGlobal(QPoint(0,0)).x();
                    qDebug() << "QCursor" << QCursor::pos().x();

            if(ruler_move == true)
            {
                ruler_move = false;
                splineSeriesRuler->clear();
                for(int i=0;i<130;i++)
                {
                    splineSeriesRuler->append(dataX.at(0) + xs_xe ,i);
                }
            }
    }

}

void TestCharts::timerTimeOut()
{
    timeout_flag = true;
}
void TestCharts::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
qDebug() << "QCursor" << QCursor::pos().x();
        }
        else if(event->button() == Qt::RightButton){
            splineSeriesRuler->clear();
        }
}

TestCharts::~TestCharts()
{

}


