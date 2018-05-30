#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCodec>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //转换为中文

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    this->setWindowTitle("移动无边");

    this->setWindowFlags(Qt::WindowCloseButtonHint); //去掉最大最小化按钮
    this->setWindowFlags(Qt::FramelessWindowHint); //无边框窗口
    this->setAttribute(Qt::WA_TranslucentBackground,true);//窗体设计透明
    this->setWindowTitle("Qt5.1窗体应用");
    this->setWindowIcon(QIcon(":/new/prefix1/ico"));

    btClose = new QPushButton(this);
    btClose->setText("关闭");
    connect(btClose, SIGNAL(clicked()), this, SLOT(close()));

    button = new QPushButton(this);
    button->setGeometry(QRect(50, 50, 100, 25));
    button->setText("按钮");
    connect(button,SIGNAL(clicked()),this, SLOT(showMainwindow2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    move(x() + dx, y() + dy);  //x() y()为widget的公有方法，求x y坐标
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x() + dx, y() + dy);
}

void MainWindow::showMainwindow2()
{
    w2.show();
}
