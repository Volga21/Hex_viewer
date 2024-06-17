#include "mymodel.h"

MyModel::MyModel(QObject * parent):QAbstractTableModel(parent)
{
	headers = { "0" , "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "A" , "B" , "C" , "D" , "E" , "F" };
}
MyModel::~MyModel()
{
}
int MyModel::rowCount(const QModelIndex& parent) const{
	return byteArray.size()/16+(byteArray.size()%16!=0);
}

int MyModel::columnCount(const QModelIndex& parent)const{
	return 16;
}

QVariant MyModel::data(const QModelIndex& index, int role) const {
	if (role == Qt::DisplayRole) {
		if (index.row() * 16 + index.column() < byteArray.size())
		{
			return QVariant(QString(byteArray[index.row() * 16 + index.column()].toUpper()));
		}
		return "00";
	}
	return QVariant();
}
QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const{
	if (role != Qt::DisplayRole)
		return QVariant();
	if (orientation == Qt::Horizontal) {
		return headers[section];
	}
	else {
		return "0x" + QString::number(section * 16, 16).toUpper();
	}
	return QVariant();
}

QString MyModel::openRiffFile(QWidget* parent ) {
	QString pathRiffFile;
	pathRiffFile = QFileDialog::getOpenFileName(parent,tr("Select riff file"), "/C", tr("Riff files (*.riff *.wav)"));
	this->riffFile.setFileName(pathRiffFile);
	if (pathRiffFile == "") {
		qDebug("openFile\n");
		return pathRiffFile;
	}
	return pathRiffFile;
}

QString MyModel::openBinFile(QWidget* parent ) {
	QString pathBinFile;
	pathBinFile = QFileDialog::getOpenFileName(parent, tr("Select bin file"), "/C", tr("Bin files (*.dat *.bin)"));
	this->binFile.setFileName(pathBinFile);
	if (pathBinFile == "") {
		return pathBinFile;
	}
	return pathBinFile;
}

void MyModel::outputHex(QWidget * parent) {
	//чтение из бинарного файла
	if (!this->binFile.open(QIODevice::ReadOnly))
		return ;
	QDataStream inBin(&binFile);
	int n;
	sizesOfFrames = 0;
	while (!binFile.atEnd()) {
		inBin >> n;
		sizesOfFrames += n;
	}
	binFile.close();

	//чтение из риф файла
	if (!this->riffFile.open(QIODevice::ReadOnly))
		return;
	QDataStream inRiff(&(this->riffFile));
	QByteArray bytes;
	byteArray.clear();

	beginResetModel();
	bytes=riffFile.read(sizesOfFrames);
	byteArray = QString(bytes.toHex(':')).split(':');
	riffFile.close();

	endResetModel();
	return;
}