#include <iostream>
#include <string>
#include "linked_list.h"

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(Student student) {
    MyNode* n = new MyNode{student, nullptr, nullptr};

    if (_head == nullptr) {
        _head = n;
        _tail = n;
    } else {
        n->previous = _tail;
        _tail->next = n;
        _tail = n;
    }

    _size++;

}

void MyList::clear() {
    MyNode* curr = _head;

    while (curr != nullptr) {
        MyNode* next = curr->next;
        delete curr;
        curr = next;
    }

    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

bool MyList::remove(const Student& student) {
    MyNode* curr = _head;

    while (curr != nullptr) {
        if (curr->value == student) {
            if (curr == _head) {
                _head = curr->next;
                if (_head) _head->previous = nullptr;
            }

            if (curr == _tail) {
                _tail = curr->previous;
                if (_tail) _tail->next = nullptr;
            }

            if (curr->previous) {
                curr->previous->next = curr->next;
            }
            if (curr->next) {
                curr->next->previous = curr->previous;
            }

            delete curr;
            _size--;
            return true;
        }
        curr = curr->next;
    }

    return false;
}

bool MyList::insert(Student student, size_t index) {
    if (index > _size) { 
        return false;
    }

    if (index == _size) {
        add(student);
        return true;
    }

    if (index == 0) {
        MyNode* node = new MyNode{student, _head, nullptr};
        if (_head) {
            _head->previous = node;
        }
        _head = node;
        if (_tail == nullptr) {
            _tail = node;
        }
        _size++;
        return true;
    }

    MyNode* curr = _head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }

    MyNode* node = new MyNode{student, curr, curr->previous};

    curr->previous->next = node;
    curr->previous = node;

    _size++;
    return true;
}
