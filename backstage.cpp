#include "backstage.h"
#include "ui_backstage.h"

BackStage::BackStage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BackStage)
{
    ui->setupUi(this);
    loadFlightsFromCsv("D:/Qtprojecets/Gobang/flights.csv");
}

BackStage::~BackStage()
{
    delete ui;
}

void BackStage::loadFlightsFromCsv(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "加载失败", "无法打开文件：" + filePath);
        return;
    }

    QTextStream in(&file);
    ui->flightsInfoTable->clear(); // 清空表格

    // 根据 Flight 类定义设置表头
    QStringList headers = {
        "航班号",
        "出发地",
        "目的地",
        "出发时间",
        "抵达时间",
        "票价",
        "折扣",
        "总座位数",
        "已售座位数"
    };
    ui->flightsInfoTable->setColumnCount(headers.size());
    ui->flightsInfoTable->setHorizontalHeaderLabels(headers);

    // 逐行读取数据并填充到表格
    int rowCount = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        // 确保字段数量与 Flight 类一致
        if (fields.size() != headers.size()) {
            // QMessageBox::warning(this, "数据错误", "CSV 文件的列数与 Flight 类不匹配！");
            continue;
        }

        int row = ui->flightsInfoTable->rowCount();
        ui->flightsInfoTable->insertRow(row);

        for (int col = 0; col < fields.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(fields[col]);
            ui->flightsInfoTable->setItem(row, col, item);
        }

        rowCount++;
    }

    file.close();
}


