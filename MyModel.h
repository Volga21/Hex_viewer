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
	int rowCount(const QModelIndex &parent = QModelIndex()) const;//���-�� �����
	int columnCount(const QModelIndex& parent = QModelIndex()) const;//���-�� ������� 
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;//����� ��� QTableView ��� ������ ������
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;//���������� ������ 
	QString openRiffFile(QWidget* parent = nullptr);//������� riff ����
	QString openBinFile(QWidget* parent = nullptr);//������� ��� ����
	void outputHex(QWidget* parent = nullptr);//������ ������ �� ������

private:
	 QStringList byteArray;
	 QFile binFile;
	 QFile riffFile;
	 unsigned int sizesOfFrames;
	 QVector<QString> headers;
};