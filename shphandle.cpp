#pragma execution_character_set("utf-8")
#include "shphandle.h"
#include"string.h"
ShpHandle::ShpHandle(QObject *parent)
	: QObject(parent)
{
	handleThread = new QThread();
	this->moveToThread(this->handleThread);
	handleThread->start();
	isdbfopen = -1;
}

ShpHandle::~ShpHandle()
{

	handleThread->quit();
	handleThread->wait();
	delete handleThread;
}
void ShpHandle::setPath(QString fullName)
{
	path = fullName.section(".", 0, 0);
}
void ShpHandle::setTableName(QString n) {
	tablename = n;
}

int ShpHandle::getCategory() {
	return category;
}
int ShpHandle::getRecodNum() {
	return recorderNum;
}
void ShpHandle::openDBase(QString dbname) {
	dba.setDatabaseName(dbname);
	if (dba.open())
		emit isOpenDataBase(1);
	else
		emit isOpenDataBase(0);
}
void ShpHandle::getName(QStringList *list) {
	foreach(QString name, name_str)
		list->append(name);

}
void ShpHandle::getType(QStringList *list) {
	foreach(QString d, dataType)
		list->append(d);

}

//获取shp信息
int ShpHandle::shpInfo() {
	shpfile.setFileName(path + ".shp");
	if (!shpfile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Cannot open file for reading: ";
		return 0;
	}
	shpfile.seek(6 * 4);
	QDataStream in(&shpfile);
	in.setVersion(QDataStream::Qt_5_6);
	in >> size;
	in.setByteOrder(QDataStream::LittleEndian);
	in >> version;
	in >> category;
	in >> Xmin;
	in >> Ymin;
	in >> Xmax;
	in >> Ymax;
	in >> Zmin;
	in >> Zmax;
	in >> Mmin;
	in >> Mmax;
	return 1;
}
//dbf信息
int ShpHandle::dbfInfo() {
	dataType.clear();
	name_str.clear();
	dbffile.setFileName(path + ".dbf");
	if (!dbffile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Cannot open file for reading: ";
		isdbfopen = 0;
		return 0;
	}
	dbffile.seek(4);
	QDataStream dbinfo(&dbffile);
	dbinfo.setByteOrder(QDataStream::LittleEndian);
	dbinfo >> recorderNum;
	dbinfo >> headerLength;
	qDebug() << headerLength;
	dbinfo >> recorderLength;
	recodnum = (headerLength - 33) / 32;
	itemlength = new quint8[recodnum];
	quint8 d;
	QByteArray buf;
	for (int i = 0;i < recodnum;i++) {
		dbffile.seek(32 * (i + 1));
		buf = dbffile.read(11);
		dbinfo >> d;
		switch (d)
		{
		case 66:
			dataType << "二进制";
			break;
		case 67:
			dataType << "字符";
			break;
		case 68:
			dataType << "日期";
			break;
		case 71:
			dataType << "OLE";
			break;
		case 76:
			dataType << "逻辑";
			break;
		case 77:
			dataType << "Memo";
			break;
		case 78:
			dataType << "数值";
			break;
		default:
			dataType << "未知类型";
			break;
		}
		dbffile.seek(32*(i+1)+16);
		dbinfo >> *(itemlength + i);
		name_str << QString(buf);
	}
	isdbfopen = 1;
	return 1;
}

void ShpHandle::handlePoint() {
	QSqlQuery query(dba);
	QString sql1 = "INSERT INTO " + tablename + "(id, 经度, 纬度";
	foreach(QString str, name_str)
	{
		sql1 += ("," + str);
	}
	sql1 += ", the_geom ) VALUES(";
	int i = 0;
	QDataStream in(&shpfile);
	in.setVersion(QDataStream::Qt_5_6);
	while (!in.atEnd()) {
		in.setByteOrder(QDataStream::BigEndian);
		int m, n;
		in >> m;
		in >> n;
		in.setByteOrder(QDataStream::LittleEndian);
		quint32 a;
		double x;
		double y;
		double z;
		double mm;
		std::string sstr= "select from";
		in >> a;
		in >> x;
		in >> y;
		in >> z;
		in >> mm;
		QString sql = sql1 + QString::number(i, 10) + "," + QString::number(x, 'f', 14) + "," + QString::number(y, 'f', 14);
		dbffile.seek(headerLength + i*(recorderLength));
		for (int j = 0;j < recodnum;j++) {
			QByteArray p = dbffile.read(*(itemlength + j));
			sql += (",'" + QString::fromLocal8Bit(p).trimmed() + "'");
		}
		sql += ",GeomFromText('POINT(" + QString::number(x, 'f', 14) + " " + QString::number(y, 'f', 14) + ")'));";
		query.exec(sql);
		emit transformed(i + 1);
		i++;
		qDebug() << sql;
	}
	delete[] itemlength;
}
void ShpHandle::handleLine() {
	QSqlQuery query(dba);
	QString sql1 = "INSERT INTO " + tablename + "(IDKEY";
	foreach(QString str, name_str)
	{
		sql1 += ("," + str);
	}
	sql1 += ", the_geom ) VALUES(";
	int i = 0;
	QDataStream in(&shpfile);
	in.setVersion(QDataStream::Qt_5_6);
	int type;
	double xi;
	double yi;
	double xa;
	double ya;
	int m, n;
	int nparts;
	int npoint;
	int parts;
	double pointx;
	double pointy;
	double zArray;
	double mArray;
	double mm[2];
	double z[2];
	int pn;
	while (!in.atEnd()) {
		in.setByteOrder(QDataStream::BigEndian);
		in >> m;
		in >> n;
		in.setByteOrder(QDataStream::LittleEndian);
		in >> type;
		in >> xi;
		in >> yi;
		in >> xa;
		in >> ya;
		in >> nparts;
		in >> npoint;
		for (int i = 0;i < nparts;i++) {
			in >> parts;
		}
		QString sql = sql1 + QString::number(i, 10);
		dbffile.seek(headerLength + i*(recorderLength)+1);
		for (int j = 0;j < recodnum;j++) {
			QByteArray p = dbffile.read(*(itemlength + j));
			sql += (",'" + QString::fromLocal8Bit(p).trimmed() + "'");
		}
		sql += ",GeometryFromText('MULTIPOLYLINE((";
		for (int j = 0;j < npoint;j++) {
			in >> pointx;
			in >> pointy;
			if (j != npoint - 1)
				sql += QString::number(pointx, 'f', 14) + " " + QString::number(pointy, 'f', 14) + ",";
			else
				sql += QString::number(pointx, 'f', 14) + " " + QString::number(pointy, 'f', 14) + "))'));";
		}
		shpfile.seek(shpfile.pos() + (2 * npoint + 4) * 8);
		query.exec(sql);
		qDebug() << sql;
		emit transformed(i + 1);
		i++;
	}
	delete[] itemlength;
}
void ShpHandle::handlePolygon() {
	QSqlQuery query(dba);
	QString sql1 = "INSERT INTO " + tablename + "(IDKEY";
	foreach(QString str, name_str)
	{
		sql1 += ("," + str);
	}
	sql1 += ", f ) VALUES(";
	int i = 0;
	QDataStream in(&shpfile);
	in.setVersion(QDataStream::Qt_5_6);
	int type;
	double xi;
	double yi;
	double xa;
	double ya;
	int m, n;
	int nparts;
	int npoint;
	int *parts;;
	QByteArray point0;
	
	int pn;
	while (!in.atEnd()) {
		in.setByteOrder(QDataStream::BigEndian);
		in >> m;
		in >> n;
		in.setByteOrder(QDataStream::LittleEndian);
		in >> type;
		in >> xi;
		in >> yi;
		in >> xa;
		in >> ya;
		in >> nparts;
		in >> npoint;
		parts = new int[nparts];
		for (int i = 0;i < nparts;i++) {
			in >> parts[i];
		}
		QString sql = sql1 + QString::number(i, 10);
		dbffile.seek(headerLength + i*(recorderLength)+1);
		for (int j = 0;j < recodnum;j++) {
			QByteArray p = dbffile.read(*(itemlength + j));
			sql += (",'" + QString::fromLocal8Bit(p).trimmed() + "'");
		}
		sql += ",:kb);";
		QByteArray wkb;
		wkb.resize(1);
		wkb[0] = (uchar)0x01;
		wkb.append(intToByte(6));
		wkb.append(intToByte(nparts));
		for (int j = 0;j < nparts;j++) {
			
			wkb.append((uchar)0x01);
			wkb.append(intToByte(3));
			wkb.append(intToByte(1));
			if (j != nparts - 1) {

				wkb.append(intToByte(parts[j+1]-parts[j]));
				wkb.append(shpfile.read((parts[j + 1] - parts[j])*16));
			}
			else {
				wkb.append(intToByte(npoint - parts[j]));
				wkb.append(shpfile.read((npoint - parts[j])*16));
			}
		}
		qDebug() << sql << nparts << npoint;
		shpfile.seek(shpfile.pos() + (2 * npoint + 4) * 8);
		query.prepare(sql);
		QVariant var(wkb);
		query.bindValue(0,var);
		query.exec();
		
		emit transformed(i + 1);
		i++;
		delete[] parts;
	}
	delete[] itemlength;
}
void ShpHandle::doWork() {
	if (isdbfopen == 1)
		switch (category)
		{
		case 15:
			handlePolygon();
			break;
		case 11:
			handlePoint();
			break;
		case 13:
			handleLine();
			break;
		default:
			break;
		}
	emit operateOver();
}
QByteArray ShpHandle::intToByte(int i)
{
	QByteArray abyte0;
	abyte0.resize(4);
	abyte0[0] = (uchar)(0x000000ff & i);
	abyte0[1] = (uchar)((0x0000ff00 & i) >> 8);
	abyte0[2] = (uchar)((0x00ff0000 & i) >> 16);
	abyte0[3] = (uchar)((0xff000000 & i) >> 24);
	return abyte0;
}