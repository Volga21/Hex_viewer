
#include "hexview.h"

HexView::HexView(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->setMinimumHeight(500);
    this->setMinimumWidth(700);

    //центральный виджет
    QWidget* centralWidget = new QWidget(this);

    //GridLayout
    QGridLayout* grid = new QGridLayout(centralWidget);

    this->setCentralWidget(centralWidget);

    //buttons
    openBinFile = new QPushButton("Bin file with size of frame",centralWidget);
    openBinFile->setMinimumWidth(150);
    openRiffFile = new QPushButton("File with frames", centralWidget);
    openRiffFile->setMinimumWidth(150);
    outputToTable = new QPushButton("Output", centralWidget);
    outputToTable->setMinimumWidth(150);
    outputToTable->setEnabled(false);

    //connect signals to slots 
    QObject::connect(openBinFile, &QPushButton::clicked, this, &HexView::slotButtonForBinFile);
    QObject::connect(openRiffFile, &QPushButton::clicked, this, &HexView::slotButtonForRiffFile);
    QObject::connect(outputToTable, &QPushButton::clicked, this, &HexView::slotButtonForOutputHex);

    //Model of data
    myModel = new MyModel(this);

    //View of model
    view = new QTableView(this);
    view->setModel(myModel);

    //Labels
    labelNameOfBinFile =  new QLabel(centralWidget);
    labelNameOfBinFile->setWordWrap(true);
    labelNameOfRiffFile = new QLabel(centralWidget);
    labelNameOfRiffFile->setWordWrap(true);


    grid->addWidget(view, 0, 0, 1, 3);
    grid->addWidget(openBinFile, 1, 0);
    grid->addWidget(openRiffFile, 1, 1);
    grid->addWidget(outputToTable, 1, 2);
    grid->addWidget(labelNameOfBinFile, 2, 0);
    grid->addWidget(labelNameOfRiffFile, 2, 1);
}

HexView::~HexView()
{
}

void HexView::slotButtonForBinFile(){
    labelNameOfBinFile->setText(myModel->openBinFile(this));
    if (labelNameOfBinFile->text()!="") {
        binFile = true;
        if (riffFile) {
            outputToTable->setEnabled(true);
        }
        return;
    }
    outputToTable->setEnabled(false);
    binFile = false;
}

void HexView::slotButtonForRiffFile(){
    labelNameOfRiffFile->setText(myModel->openRiffFile(this));
    if (labelNameOfRiffFile->text()!="") {
        riffFile = true;
        if (binFile) {
            outputToTable->setEnabled(true);
        }
        return;
    }
    outputToTable->setEnabled(false);
    riffFile = false;
}

void HexView::slotButtonForOutputHex() {
    myModel->outputHex(this);
}
