#include "Widget.h"
#include "ui_Widget.h"
#include "DuWebServer.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mServer = new DuWebServer(this);

    ui->portSpinBox->setMaximum(INT_MAX);
    ui->portSpinBox->setMinimum(0);
    ui->portSpinBox->setValue(3333);

    connect(mServer, &DuWebServer::fileErrorHasOccurred,
            [&](const QString &errorString) {
        QMessageBox::critical(this, "Error", errorString);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startWebServerPushButton_clicked()
{
    if (mServer->startWebServer(ui->portSpinBox->value())) {
        QMessageBox::information(this, "OK", "OK");
    } else {
        QMessageBox::critical(this, "Error", "Server Error");
    }
}
