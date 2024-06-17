#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HexView.h"
#include "HexView.h"
#include <QPushButton>
#include <QGridLayout>
#include "MyModel.h"
#include <QTableView>
#include <QString>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QFrame>
#include <QLabel>

class HexView : public QMainWindow
{
    Q_OBJECT

public:
    HexView(QWidget *parent = nullptr);
    ~HexView();
    
signals:
    void signalButtonForBinFile();
    void signalButtonForRiffFile();

public slots:
    void slotButtonForBinFile();
    void slotButtonForRiffFile();
    void slotButtonForOutputHex();

private:
    Ui::HexViewClass ui;
    MyModel * myModel;
    bool binFile=false, riffFile=false;
    QPushButton* openBinFile;
    QPushButton* openRiffFile;
    QPushButton* outputToTable;
    QLabel* labelNameOfBinFile;
    QLabel* labelNameOfRiffFile;
    QTableView* view;
};
