#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QWidget>

#include "flightgraph.h"

namespace Ui {
class UserInterface;
}

class UserInterface : public QWidget
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();

private slots:
    void on_origin_input_edit_textChanged();

    void on_destination_input_edit_textChanged();

    void on_reverse_button_clicked();

private:
    Ui::UserInterface *ui;
    FlightGraph graph;
};

#endif // USERINTERFACE_H
