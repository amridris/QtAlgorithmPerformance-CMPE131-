#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arraydatabase.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Program banner for GUI
    QPixmap pix("C:/Users/amer0/Pictures/desktop_banner.png");
    int w = ui->Desktop_banner->width();
    int h = ui->Desktop_banner->height();
    // No need to change it is for graphical purpose 
    ui->Desktop_banner->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatioByExpanding));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generate_database_clicked()
{

    //Add room prices to the vectors
    this->database_insertion.createDatabase(ui->spinBox->value());
    this->database_selection.createDatabase(ui->spinBox->value());
    this->database_merge.createDatabase(ui->spinBox->value());
    this->database_quickSort.createDatabase(ui->spinBox->value());

    //send message to GUI that databases were created
    QMessageBox::information(this, "Progress", "Database created!");
}

void MainWindow::on_print_database_clicked()
{
   //print the database. Used for debugging
    std::cout<<"~~~~~~~~~~~~~~~~INSERTION SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_insertion.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~SELECTION SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_selection.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~MERGE SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_merge.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~Randomized QuickSort ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_quickSort.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~END!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}



void MainWindow::on_Insertion_sort_clicked()
{
    QElapsedTimer timer;
    timer.start();
   int frequency = ui->frequency_box->value();
   for(int i=0; i<frequency; i++){
        this->database_insertion.changePrice();
        this->database_insertion.insertionSort();
   }
   this->insertion_time = timer.elapsed();
   QString value = QString::number(this->insertion_time);
   QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using insertion sort");


}

void MainWindow::on_selection_sort_clicked()
{
   QElapsedTimer timer;
   timer.start();
   int frequency = ui->frequency_box->value();
   for(int i=0; i<frequency; i++){
        this->database_selection.changePrice();
        this->database_selection.selectionSort();
   }
   this->selection_time = timer.elapsed();
   QString value = QString::number(this->selection_time);
   QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using selection sort");

 }

void MainWindow::on_merge_sort_clicked()
{

    QElapsedTimer timer;
    timer.start();
    int size = this->database_merge.list_size-1;
    int frequency = ui->frequency_box->value();
    for(int i=0; i<frequency; i++){
         this->database_merge.changePrice();
         this->database_merge.mergeSort(0, size);
    }
    this->merge_time = timer.elapsed();
    QString value = QString::number(this->merge_time);
    QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using Merge sort");
}

void MainWindow::on_quick_sort_clicked()
{
    QElapsedTimer timer;
    timer.start();
    int size = this->database_merge.list_size-1;
    int frequency = ui->frequency_box->value();
    for(int i=0; i<frequency; i++){
         this->database_quickSort.changePrice();
         this->database_quickSort.randomizedQuickSort(0, size);
    }
    this->random_quick_time = timer.elapsed();
    QString value = QString::number(this->random_quick_time);
    QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using Quicksort");
}


