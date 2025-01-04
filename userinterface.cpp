#include "userinterface.h"
#include "ui_userinterface.h"

// Qt header files
#include <QString>

UserInterface::UserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserInterface)
{
    ui->setupUi(this);
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::on_origin_input_edit_textChanged()
{
    QString origin = ui->origin_input_edit->toPlainText();

    // 打印或处理内容
    qDebug() << "出发地:" << origin;
}


void UserInterface::on_destination_input_edit_textChanged()
{
    QString destination = ui->destination_input_edit->toPlainText();

    // 打印或处理内容
    qDebug() << "目的地:" << destination;
}


void UserInterface::on_reverse_button_clicked()
{
    QString origin = ui->origin_input_edit->toPlainText();
    QString destination = ui->destination_input_edit->toPlainText();
    ui->origin_input_edit->setPlainText(destination);
    ui->destination_input_edit->setPlainText(origin);
}

