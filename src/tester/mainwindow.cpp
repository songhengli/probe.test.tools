#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test_dev.h"
#include <QDebug>
#include <QtSql/QSqlError>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    test_charts = new TestCharts();
    ui->gridLayout_4->addWidget(test_charts, 2, 0, 1, 10);

    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver,drivers)
    {
        qDebug() << driver;
    }

    sqlDatabase = QSqlDatabase::addDatabase("QMYSQL");
    sqlDatabase.setHostName("127.0.0.1");
    sqlDatabase.setUserName("root");
    sqlDatabase.setPassword("aeonmed");
    sqlDatabase.setDatabaseName("probe_test_db");

    if(!sqlDatabase.open())
    {
        qDebug() << "连接数据库错误" << sqlDatabase.lastError() << endl;
    }
    else
    {
        qDebug() << "连接数据库成功" << endl;
    }
    QSqlQuery query(sqlDatabase);

    query.exec("select * from test_item_00000001_data");
    while (true == query.next()) {
        dataY.append(query.value(2).toUInt());
        dataX.append(query.value(1).toUInt());

        qDebug() << query.value(0)
                 <<query.value(1)
                 <<query.value(2)
                 <<query.value(3).toString();
    }

    test_charts->curveDraw(dataX,dataY);

    qDebug() << "MainWindow" << this->x() <<this->y();
/*
    for(int i=0;i<dataY.size();i++)
    {
        splineSeries->append(dataX.at(i),dataY.at(i));
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


