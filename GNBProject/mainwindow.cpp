#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showList();
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
      this, SLOT(onListItemClicked(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showList()
{
    /*
QListView::item:selected {
     border: 1px solid #6a6ea9;
 }
 QListView::item:selected:!active {
     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                 stop: 0 #FFFFFF, stop: 1 #FFFFFF);
                                 //stop: 0 #ABAFE5, stop: 1 #8588B2);
 }
 QListView::item:selected:active {
     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFFFFF, stop: 1 #FFFFFF);
     //                            stop: 0 #6a6ea9, stop: 1 #888dd9);
 }
*/
    qDebug("showList");
    for (int i = 0; i<10; i++) {

        QWidget *widget = new QWidget(ui->listWidget);
        widget->setStyleSheet("background:transparent;");

        QWidget *frontArea = new QWidget(widget);
        frontArea->setFixedHeight(32);
        frontArea->setFixedWidth(130);

        QLabel *lab_node = new QLabel(frontArea);
        lab_node->setText("节点" + QString::number(1000+i));

        QLabel *lab_ip = new QLabel(frontArea);
        lab_ip->setText("虚拟ip： 192.168.1.1");

        QWidget *backArea = new QWidget(widget);
        backArea->setFixedSize(158, 32);

        QProgressBar *pg_data = new QProgressBar(backArea);
        pg_data->setTextVisible(false);
        pg_data->setFixedHeight(12);
        pg_data->setStyleSheet("QProgressBar{ border:none; background:rgb(230, 230, 230); border-radius:0px; text-align:center; color:gray }\
                                QProgressBar::chunk{ background:rgb(71, 137, 250); border-radius:0px; }");

        QLabel *lab_speed = new QLabel(backArea);
        lab_speed->setText("0 B/s");

        QLabel *lab_status = new QLabel(widget);
        lab_status->setText(QStringLiteral("等待中"));
        lab_status->setStyleSheet("QLabel{padding-left:0px;padding-right:0px;}");
        lab_status->setFixedWidth(55);

        QVBoxLayout *verLayout = new QVBoxLayout;
        verLayout->setContentsMargins(0, 0, 0, 0);
        verLayout->setMargin(0);
        verLayout->setSpacing(0);
        verLayout->addWidget(lab_node);
        verLayout->addWidget(lab_ip);
        frontArea->setLayout(verLayout);

        QVBoxLayout *verLayout2 = new QVBoxLayout;
        verLayout2->setContentsMargins(0, 0, 0, 0);
        verLayout2->setMargin(0);
        verLayout2->setSpacing(0);
        verLayout2->addWidget(pg_data);
        verLayout2->addWidget(lab_speed);
        backArea->setLayout(verLayout2);

        QHBoxLayout *layout = new QHBoxLayout(widget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setMargin(0);
        layout->setSpacing(0);

        layout->addWidget(frontArea);
        layout->addWidget(backArea);
        layout->addWidget(lab_status);
        widget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem();
        QSize size = item->sizeHint();
        item->setSizeHint(QSize(size.width(), 56));
        ui->listWidget->addItem(item);
        widget->setSizeIncrement(size.width(), 56);
        ui->listWidget->setItemWidget(item, widget);
    }
}

void MainWindow::onListItemClicked(QListWidgetItem* item)
{
    item->setBackground(QColor("white"));

    qDebug("onListItemClicked");
    if (ui->listWidget->item(0) == item) {
    }
}