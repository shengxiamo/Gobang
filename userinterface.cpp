#include "userinterface.h"
#include "ui_userinterface.h"

// Qt header files
#include <QString>
#include <QFile>

UserInterface::UserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserInterface)
{
    ui->setupUi(this);

    read_csv();
    for (auto flight : flights) {
        qDebug() << flight.toString();
    }
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

void UserInterface::read_csv()
{
    QFile file("D:/Qtprojecets/Gobang/flights.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);


    int rowCount = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        // 确保字段数量与 Flight 类一致
        if (fields.size() != 9) {
            continue;
        }

        List<QString> str_list;
        for (auto str : fields) {
            str_list.push_back(str);
        }

        flights.push_back(Flight(str_list));

        rowCount++;
    }

    file.close();
}

