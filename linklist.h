#ifndef LINKLIST_H
#define LINKLIST_H

#include <memory>
#include <iostream>
#include <stdexcept>

namespace data_struct {

template <typename T>
class SinglyLinkNode {
public:
    SinglyLinkNode(const T& data) {
        this->data = std::make_shared<T>(data);
        this->next = nullptr;
    }

    SinglyLinkNode() {
        this->data = nullptr;
        this->next = nullptr;
    }

    T getData() const {
        return *data;
    }

    T* getDataPtr() {
        return data.get();
    }

    std::shared_ptr<SinglyLinkNode<T>> getNext() const {
        return next;
    }

    void setNext(std::shared_ptr<SinglyLinkNode<T>> next) {
        this->next = next;
    }

private:
    std::shared_ptr<T> data;
    std::shared_ptr<SinglyLinkNode<T>> next;
};

template <typename T>
class SinglyLinkeList {
public:
    SinglyLinkeList() {
        front = std::make_shared<SinglyLinkNode<T>>();
        rear = front;
    }

    ~SinglyLinkeList() {
        clear();  // 智能指针自动释放内存
    }

    void display() const {
        auto current = front->getNext();
        while (current != nullptr) {
            std::cout << current->getData() << " -> ";
            current = current->getNext();
        }
        std::cout << "NULL\n";
    }

    void addtoTail(const T& data) {
        auto newNode = std::make_shared<SinglyLinkNode<T>>(data);
        rear->setNext(newNode);
        rear = newNode;
    }

    T* at(long long index) const {
        if (index < 0) {
            throw std::out_of_range("Index cannot be negative.");
        }

        auto current = front->getNext();
        long long currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) {
                return current->getDataPtr();
            }
            current = current->getNext();
            currentIndex++;
        }

        throw std::out_of_range("Index out of range.");
    }

    size_t size() const {
        size_t count = 0;
        auto current = front->getNext();
        while (current != nullptr) {
            count++;
            current = current->getNext();
        }
        return count;
    }

    void clear() {
        front->setNext(nullptr);
        rear = front;
    }

private:
    std::shared_ptr<SinglyLinkNode<T>> front;
    std::shared_ptr<SinglyLinkNode<T>> rear;
};

}  // namespace data_struct

#endif  // LINKLIST_H
