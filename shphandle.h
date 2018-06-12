#ifndef SHPHANDLE_H
#define SHPHANDLE_H
#include<QObject>
#include<QFile>
#include<QThread>
#include <QDataStream>
#include<QDebug>
#include<qsqlquery.h>
class ShpHandle :public QObject
{
	Q_OBJECT
private:
	QString tablename;
	QString path;
	QFile shpfile;
	QFile dbffile;
	int isdbfopen;
	int size;
	int version;
	int recodnum;
	int category;//shp种类
	int recorderNum;//dbf记录条数
	quint16 headerLength;//dbf头长度
	quint16 recorderLength;//dbf纪录长度
	quint8 *itemlength;//dbf纪录项长度
	QStringList dataType;//纪录项种类
	QStringList name_str;
	double Xmin;
	double Ymin;
	double Xmax;
	double Ymax;
	double Zmin;
	double Zmax;
	double Mmin;
	double Mmax;
	QSqlDatabase dba = QSqlDatabase::addDatabase("QODBC");
	QThread *handleThread;

public:
	ShpHandle(QObject *parent = NULL);
	~ShpHandle();
	int shpInfo();
	void setPath(QString);
	void handlePoint();
	void handleLine();
	void handlePolygon();
	QByteArray intToByte(int);
	void setTableName(QString);
	int dbfInfo();
	int getRecodNum();
	int getCategory();
	void getName(QStringList*);
	void getType(QStringList*);

	public slots:
	void doWork();
	void openDBase(QString);
signals:
	void operateOver();
signals:
	void isOpenDataBase(int);
signals:
	void transformed(int);
};

#endif