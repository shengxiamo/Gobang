#ifndef LIST_H
#define LIST_H

#include <stdexcept>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val = T(), Node* p = nullptr, Node* n = nullptr)
            : data(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    // 迭代器类
    class iterator {
        Node* current;
    public:
        iterator(Node* ptr = nullptr) : current(ptr) {}

        T& operator*() { return current->data; }
        const T& operator*() const { return current->data; }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            current = current->next;
            return tmp;
        }

        bool operator==(const iterator& other) const { return current == other.current; }
        bool operator!=(const iterator& other) const { return current != other.current; }

        friend class List;
    };

    // 构造函数和析构函数
    List() : head(nullptr), tail(nullptr), count(0) {}

    ~List() { clear(); }

    // 拷贝构造函数
    List(const List& other) : head(nullptr), tail(nullptr), count(0) {
        for (const auto& item : other) {
            push_back(item);
        }
    }

    // 赋值运算符
    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            for (const auto& item : other) {
                push_back(item);
            }
        }
        return *this;
    }

    // 容量操作
    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    // 元素访问
    T& front() { return head->data; }
    const T& front() const { return head->data; }
    T& back() { return tail->data; }
    const T& back() const { return tail->data; }

    // 修改操作
    void push_back(const T& val) {
        Node* newNode = new Node(val, tail, nullptr);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        ++count;
    }

    void push_front(const T& val) {
        Node* newNode = new Node(val, nullptr, head);
        if (head) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        ++count;
    }

    void insert(iterator pos, const T& val) {
        if (pos == begin()) {
            push_front(val);
        } else if (pos == end()) {
            push_back(val);
        } else {
            Node* curr = pos.current;
            Node* newNode = new Node(val, curr->prev, curr);
            curr->prev->next = newNode;
            curr->prev = newNode;
            ++count;
        }
    }

    void erase(iterator pos) {
        if (pos == end()) return;

        Node* curr = pos.current;
        if (curr->prev) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }
        if (curr->next) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
        }
        delete curr;
        --count;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }

    // 迭代器方法
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(nullptr); }
};

#endif // LIST_H
