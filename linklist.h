#ifndef LINKLIST_H
#define LINKLIST_H

#include <memory>
#include <iostream>

namespace data_struct {

    template <typename T>
    class SinglyLinkNode {
    public:
        SinglyLinkNode(const T &data) {
            this->data = std::make_shared<T>(data);
            this->next = nullptr;
        }

        SinglyLinkNode() {
            this->data = nullptr;
            this->next = nullptr;
        }

        T getData() {
            return *data;
        }

        std::shared_ptr<SinglyLinkNode<T>> getNext() {
            return next;
        }

        void setNext(std::shared_ptr<SinglyLinkNode<T>> next) {
            this->next = next;
        }

    private:
        std::shared_ptr<T> data;  // 使用指针避免对象拷贝，并且使用智能指针自动管理内存，防止内存泄漏
        std::shared_ptr<SinglyLinkNode<T>> next;  // 指向下一个节点的共享指针
    };

    template <typename T>
    class SinglyLinkeList {  // 只有头指针的单向列表
    public:
        SinglyLinkeList() {
            front = std::make_shared<SinglyLinkNode<T>>();
            rear = front;
        }

        ~SinglyLinkeList() {
            ; // 使用智能指针，不需要手动释放内存
        }

        void display() {
            std::shared_ptr<SinglyLinkNode<T>> tmp = front->getNext();
            while (tmp != nullptr) {
                std::cout << tmp->getData() << "->";
                tmp = tmp->getNext();
            }
            std::cout << "NULL\n";
        }

        void addtoTail(const T &data) {
            auto newNode = std::make_shared<SinglyLinkNode<T>>(data);
            rear->setNext(newNode);
            rear = newNode;
        }

    private:
        std::shared_ptr<SinglyLinkNode<T>> front; // 带头节点的指针，方便插入删除操作
        std::shared_ptr<SinglyLinkNode<T>> rear;  // 记录尾指针是为了在尾部插入时不用从头结点遍历
    };

}  // namespace data_struct

#endif  // LINKLIST_H
