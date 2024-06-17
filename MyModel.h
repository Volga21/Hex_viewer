#pragma once
#include <QAbstractTableModel>
#include <QFile>
#include <QList>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QIODevice>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QString>
#include <sstream>
#include <QCHar>

class MyModel : public QAbstractTableModel {
	Q_OBJECT

public:
	explicit MyModel(QObject *parent = nullptr);
	~MyModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;//кол-во строк
	int columnCount(const QModelIndex& parent = QModelIndex()) const;//кол-во колонок 
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;//метод для QTableView для взятия данных
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;//установить хедоры 
	QString openRiffFile(QWidget* parent = nullptr);//открыть riff файл
	QString openBinFile(QWidget* parent = nullptr);//открыть бин файл
	void outputHex(QWidget* parent = nullptr);//чтение данных из файлов

private:
	 QStringList byteArray;
	 QFile binFile;
	 QFile riffFile;
	 unsigned int sizesOfFrames;
	 QVector<QString> headers;
};