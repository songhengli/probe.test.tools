#ifndef TEST_CHARTS_H
#define TEST_CHARTS_H

#include <QObject>
#include <QChartView>
#include <QSplineSeries>
#include <QValueAxis>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

class TestCharts:public QChartView
{
    Q_OBJECT

public:

    TestCharts();  
    ~TestCharts();
    void curveDraw(int x,int y);
    void curveDraw( QList<int> &x, QList<int> &y);

private:

    int maxX;
    int maxY;
    int cnt;
    int ruler_xs;
    int ruler_xe;
    int xs_xe;
    int axisX_xs;
    int axisX_xe;

    QPoint press_point;
    QPoint release_point;
    bool ruler_move;
    bool timeout_flag;


    QValueAxis *axisY;
    QValueAxis *axisX;

    QList<int> dataY;
    QList<int> dataX;

    QSplineSeries *splineSeries;
    QSplineSeries *splineSeriesRuler;

    QChart *chart;

    QTimer *timer;

    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void timerTimeOut();


};
#endif // MAINWINDOW_H
