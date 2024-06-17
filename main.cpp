#include "HexView.h"
#include <QtWidgets/QApplication>
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include "MyModel.h"
#include <iostream>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexView *w=new HexView();

    w->show();

    a.exec();

}
