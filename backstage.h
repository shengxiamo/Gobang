#ifndef BACKSTAGE_H
#define BACKSTAGE_H

#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class BackStage;
}

class BackStage : public QWidget
{
    Q_OBJECT

public:
    explicit BackStage(QWidget *parent = nullptr);
    ~BackStage();
    void loadFlightsFromCsv(const QString &filePath);

private slots:

    void on_saveButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::BackStage *ui;
};

#endif // BACKSTAGE_H
