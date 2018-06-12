#pragma execution_character_set("utf-8")
#include "shp.h"

SHP::SHP(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	sh = new ShpHandle();
	view = new QWebEngineView(ui.page_3);
	model = new QStandardItemModel(this);
	preview = 0;
	ui.tableView->setStyleSheet(QStringLiteral("QTableView {"
		"gridline-color:#bfdeff; "
		"alternate-background-color:#00ff00;"
		"selection-color:white;"
		"selection-background-color:#008bff;"
		"border: 1px groove #bfdeff;"
	"}"
	"QHeaderView {"
		";font-family: \"微软雅黑\"; font-size:15px; font-weight:bold;"
	"}"
	"QHeaderView::section {"
		"background:white;"
		"border: 1px solid #bfdeff;"
	"} "
	"QTableView QTableCornerButton::section {"
		"color: red;"
		"background:#bfdeff;"
		"border: 0px solid #f6f7fa;"
	"}"
	));
	ui.progressBar->setValue(0);
	ui.progressBar->setStyleSheet("QProgressBar{border:1px solid #bfdeFF;"
		"background:#fff;"
       "text-align:center;"
		"color:#000;"
       "border-radius:10px;}"
       "QProgressBar::chunk{"
		"border-radius:5px;"
		"background:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 #bfdeff,stop:1 #008bff);}");
	ui.tableView->setModel(model);
	ui.tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.actionOpen->setEnabled(false);
	ui.actionSetting->setEnabled(false);
	ui.actionTran->setEnabled(false);
	connect(this, SIGNAL(startToTran()), sh, SLOT(doWork()));

	connect(ui.actionTran, SIGNAL(triggered()), this, SLOT(tran()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(fecthShp()));
	connect(ui.actionSetting, SIGNAL(triggered()), this, SLOT(setting()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(open()));
	connect(ui.actionHelp, SIGNAL(triggered()), this, SLOT(help()));
	connect(sh, SIGNAL(isOpenDataBase(int)), this, SLOT(jumppage(int)));
	connect(this, SIGNAL(set(QString)), sh, SLOT(openDBase(QString)));
	connect(sh, SIGNAL(transformed(int)), this, SLOT(setBarValue(int)));
	connect(sh, SIGNAL(operateOver()), this, SLOT(tranOver()));
}

SHP::~SHP()
{
	delete sh;
	delete model;
	model = NULL;
	delete view;
	view = NULL;
}
void SHP::tran() {
	ui.actionOpen->setEnabled(false);
	ui.actionSetting->setEnabled(false);
	ui.actionTran->setEnabled(false);
	sh->setTableName(ui.lineEdit->text());
	emit startToTran();
}
void SHP::tranOver() {
	ui.actionOpen->setEnabled(true);
	ui.actionSetting->setEnabled(true);
	ui.actionTran->setEnabled(true);
}
void SHP::jumppage(int isok) {
	if (isok) {
		ui.label_2->setText("连接成功");
		ui.actionOpen->setEnabled(true);
		ui.actionSetting->setEnabled(true);
		ui.actionTran->setEnabled(true);
		ui.stackedWidget->setCurrentIndex(1);
	}
	else {
		ui.label_2->setText("连接失败，请重试");
	}
}
void SHP::setBarValue(int value) {
	ui.progressBar->setValue(value);
}
void SHP::open() {
	ui.actionOpen->setEnabled(false);
	ui.actionSetting->setEnabled(false);
	ui.actionTran->setEnabled(false);
	if (!ui.lineEdit_2->text().isEmpty()) {
		ui.label_2->setText("正在连接");
		emit set(ui.lineEdit_2->text());
	}
	else
		ui.label_2->setText("请输入DSN");
}
void SHP::help() {
	int current = ui.stackedWidget->currentIndex();
	if (current != 2) {
		preview = current;
		view = new QWebEngineView(ui.page_3);
		view->setGeometry(QRect(0, 0, 1111, 671));
		view->setUrl(QUrl("https://www.baidu.com/"));
		ui.stackedWidget->setCurrentIndex(2);
	}
	else {
		ui.stackedWidget->setCurrentIndex(preview);
		delete view;
		view = NULL;
	}
}
void SHP::setting() {
	if (ui.stackedWidget->currentIndex() != 0)
		ui.stackedWidget->setCurrentIndex(0);
	else
		ui.stackedWidget->setCurrentIndex(1);
}
void SHP::fecthShp()
{
	filepath = QFileDialog::getOpenFileName(this, "open", "../", "Shapefile(*.shp)");
	if (!filepath.isEmpty()) {
		ui.progressBar->setValue(0);
		ui.labe_name->setText(filepath.section('/', -1, -1));
		ui.label_path->setText(filepath.section('/', 0, -2));
		sh->setPath(filepath);
		sh->shpInfo();
		sh->dbfInfo();
		int type = sh->getCategory();
		ui.progressBar->setMaximum(sh->getRecodNum());
		if (type == 11 || type == 13 || type == 15)
			ui.label_type->setStyleSheet("color:green;");
		else
			ui.label_type->setStyleSheet("color:red;");
		ui.label_type->setText(QString::number(type, 10));
		ui.label_num->setText(QString::number(sh->getRecodNum(), 10));
		QStringList name;
		name.clear();
		sh->getName(&name);
		QStringList datatype;
		datatype.clear();
		sh->getType(&datatype);
		int i = 0;
		model->clear();
		model->setRowCount(2);
		model->setHeaderData(0, Qt::Vertical, "字段");
		model->setHeaderData(1, Qt::Vertical, "类型");
		ui.tableView->verticalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
		ui.tableView->verticalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
		foreach(QString n, name) {
			model->setItem(0, i, new QStandardItem(n));
			model->item(0, i)->setForeground(QBrush(QColor(0, 155, 255)));
			model->item(0, i)->setTextAlignment(Qt::AlignCenter);
			model->setItem(1, i, new QStandardItem(datatype[i]));
			model->item(1, i)->setTextAlignment(Qt::AlignCenter);
			i++;
		}
	}
}