#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<QPixmap>
#include<random>
#include<arraydatabase.h>
#include<Qtime>
#include<QElapsedTimer>
#include<Qstring>
#include<arraydatabase.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_generate_database_clicked();

    void on_print_database_clicked();
    
    void on_Insertion_sort_clicked();

    void on_selection_sort_clicked();

    void on_merge_sort_clicked();

    void on_quick_sort_clicked();

private:
    Ui::MainWindow *ui;

public:
    QString hotelName;
    int roomNum=0;
    arrayDatabase database_insertion;
    arrayDatabase database_selection;
    arrayDatabase database_merge;
    arrayDatabase database_quickSort;
    double insertion_time;
    double selection_time;
    double merge_time;
    double random_quick_time;
    int price_change_frequency = 0;

};
#endif // MAINWINDOW_H
