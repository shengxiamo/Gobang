#include "mainwindow.h"

#include <QApplication>

#include "linklist.h"

int main(int argc, char   *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    data_struct::SinglyLinkeList<int> list;

    // Add data to the tail
    list.addtoTail(10);
    list.addtoTail(20);
    list.addtoTail(30);
    list.addtoTail(40);
    list.addtoTail(50);

    // Display the list
    std::cout << "Linked List: ";
    list.display();

    // Add more elements
    list.addtoTail(60);
    list.addtoTail(70);

    // Display the list again
    std::cout << "Updated Linked List: ";
    list.display();

    return 0;

}
