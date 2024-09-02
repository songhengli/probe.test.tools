#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "test_dev.h"
#include "test_env.h"
#include "test_item.h"
#include "test_item_data.h"
#include "test_type.h"
#include "test_charts.h"
#include <qchartview.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QTimer>
#include <QMouseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:


private:
    Ui::MainWindow *ui;

    QList<TestDev> *test_dev_table;
    QList<TestEnv> *test_env_table;
    QList<TestType> *test_type_table;
    QList<TestItem> *test_item_table;
    QList<TestItemData> *test_item_data_table;

    QSqlDatabase sqlDatabase;
    QSqlTableModel *model;

    TestCharts *test_charts;

    QList<int> dataY;
    QList<int> dataX;

private slots:




};
#endif // MAINWINDOW_H
