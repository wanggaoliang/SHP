/********************************************************************************
** Form generated from reading UI file 'shp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHP_H
#define UI_SHP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SHPClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionTran;
    QAction *actionSetting;
    QAction *actionHelp;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QWidget *page;
    QLabel *labe_name;
    QLabel *label_path;
    QLabel *label_type;
    QLabel *label_num;
    QLabel *label;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QProgressBar *progressBar;
    QWidget *page_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SHPClass)
    {
        if (SHPClass->objectName().isEmpty())
            SHPClass->setObjectName(QStringLiteral("SHPClass"));
        SHPClass->resize(919, 774);
        SHPClass->setStyleSheet(QStringLiteral("background:#FFF;"));
        actionOpen = new QAction(SHPClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SHP/f.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExit = new QAction(SHPClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SHP/e.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionTran = new QAction(SHPClass);
        actionTran->setObjectName(QStringLiteral("actionTran"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SHP/u.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTran->setIcon(icon2);
        actionSetting = new QAction(SHPClass);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SHP/s.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetting->setIcon(icon3);
        actionHelp = new QAction(SHPClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/SHP/h.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon4);
        centralWidget = new QWidget(SHPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 911, 671));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 100, 411, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(28);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 230, 291, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QStringLiteral("border:3px groove #bfdeff;border-radius:10px;padding:2px 4px;"));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 310, 291, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QStringLiteral("border:2px groove #008bff;border-radius:10px;padding:2px 4px;color:#fff;background:#008bff;"));
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        labe_name = new QLabel(page);
        labe_name->setObjectName(QStringLiteral("labe_name"));
        labe_name->setGeometry(QRect(360, 20, 351, 31));
        labe_name->setFont(font1);
        labe_name->setAlignment(Qt::AlignCenter);
        label_path = new QLabel(page);
        label_path->setObjectName(QStringLiteral("label_path"));
        label_path->setGeometry(QRect(360, 91, 351, 31));
        label_path->setFont(font1);
        label_path->setAlignment(Qt::AlignCenter);
        label_type = new QLabel(page);
        label_type->setObjectName(QStringLiteral("label_type"));
        label_type->setGeometry(QRect(360, 162, 351, 31));
        label_type->setFont(font1);
        label_type->setStyleSheet(QStringLiteral("color:green;"));
        label_type->setAlignment(Qt::AlignCenter);
        label_num = new QLabel(page);
        label_num->setObjectName(QStringLiteral("label_num"));
        label_num->setGeometry(QRect(360, 231, 351, 31));
        label_num->setFont(font1);
        label_num->setAlignment(Qt::AlignCenter);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 450, 341, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        label->setFont(font3);
        label->setStyleSheet(QLatin1String("color:gray;\n"
""));
        tableView = new QTableView(page);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(110, 500, 731, 151));
        tableView->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(360, 302, 351, 41));
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QStringLiteral("border:3px groove #bfdeff;border-radius:10px;padding:2px 4px;"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 20, 101, 31));
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("color:gray;"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 91, 101, 31));
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color:gray;"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 162, 101, 31));
        label_5->setFont(font2);
        label_5->setStyleSheet(QStringLiteral("color:gray;"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 231, 111, 31));
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral("color:gray;"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 302, 101, 31));
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("color:gray;"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 373, 101, 31));
        label_8->setFont(font2);
        label_8->setStyleSheet(QStringLiteral("color:gray;"));
        progressBar = new QProgressBar(page);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(360, 373, 351, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        progressBar->setFont(font4);
        progressBar->setStyleSheet(QStringLiteral("background:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 #bfdeff,stop:1 #008bff);"));
        progressBar->setValue(100);
        progressBar->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);
        SHPClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SHPClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 26));
        menuBar->setStyleSheet(QStringLiteral("background:#fff;"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        SHPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SHPClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral(""));
        SHPClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SHPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SHPClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionExit);
        menu_2->addAction(actionTran);
        menu_2->addAction(actionSetting);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionTran);
        mainToolBar->addAction(actionSetting);
        mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionExit);

        retranslateUi(SHPClass);

        QMetaObject::connectSlotsByName(SHPClass);
    } // setupUi

    void retranslateUi(QMainWindow *SHPClass)
    {
        SHPClass->setWindowTitle(QApplication::translate("SHPClass", "SHP", 0));
        actionOpen->setText(QApplication::translate("SHPClass", "open", 0));
        actionExit->setText(QApplication::translate("SHPClass", "exit", 0));
        actionTran->setText(QApplication::translate("SHPClass", "tran", 0));
        actionSetting->setText(QApplication::translate("SHPClass", "setting", 0));
        actionHelp->setText(QApplication::translate("SHPClass", "help", 0));
        label_2->setText(QApplication::translate("SHPClass", "\350\277\236\346\216\245\345\210\260ODBC\346\272\220", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("SHPClass", "DSN", 0));
        pushButton->setText(QApplication::translate("SHPClass", "\350\277\236\346\216\245", 0));
        labe_name->setText(QApplication::translate("SHPClass", "name", 0));
        label_path->setText(QApplication::translate("SHPClass", "path", 0));
        label_type->setText(QApplication::translate("SHPClass", "type", 0));
        label_num->setText(QApplication::translate("SHPClass", "num", 0));
        label->setText(QApplication::translate("SHPClass", "dbf\345\255\227\346\256\265\347\261\273\345\236\213\357\274\232", 0));
        label_3->setText(QApplication::translate("SHPClass", "\346\226\207\344\273\266\345\220\215\357\274\232", 0));
        label_4->setText(QApplication::translate("SHPClass", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", 0));
        label_5->setText(QApplication::translate("SHPClass", "\347\233\256\346\240\207\347\261\273\345\236\213\357\274\232", 0));
        label_6->setText(QApplication::translate("SHPClass", "\347\272\252\345\275\225\351\241\271\346\225\260\347\233\256\357\274\232", 0));
        label_7->setText(QApplication::translate("SHPClass", "\350\241\250\345\220\215\357\274\232", 0));
        label_8->setText(QApplication::translate("SHPClass", "\350\277\233\345\272\246\357\274\232", 0));
        menu->setTitle(QApplication::translate("SHPClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("SHPClass", "\346\223\215\344\275\234", 0));
    } // retranslateUi

};

namespace Ui {
    class SHPClass: public Ui_SHPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHP_H
