#ifndef SHP_H
#define SHP_H

#include <QtWidgets/QMainWindow>
#include "ui_shp.h"
#include<QFileDialog>
#include"shphandle.h"
#include<qsqldatabase.h>
#include<QStandardItemModel>
#include<QWebEngineView>
class SHP : public QMainWindow
{
	Q_OBJECT

public:
	SHP(QWidget *parent = 0);
	~SHP();
public slots:
	void fecthShp();
	void tran();
	void setting();
	void open();
	void help();
	void jumppage(int);
	void setBarValue(int);
	void tranOver();
signals:
	void startToTran();
signals:
	void set(QString);
private:
	Ui::SHPClass ui;
	ShpHandle *sh;
	QString filepath;
	
	QStandardItemModel *model;
	int preview;
	QWebEngineView * view;
};

#endif // SHP_H

