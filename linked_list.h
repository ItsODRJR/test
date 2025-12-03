// provided. do not modify. do not submit.
#pragma once

#include <string>
#include <iostream>

/**
 * Represents a student with a name and a grade.
 *
 * @param name
 * @param score
 */
struct Student {
    std::string name;
    int score = 0;
};

/**
 * Test for student equality. One student is equal to the other if they have equal names.
 *
 * @param lhs the one student
 * @param rhs the other student
 * @returns `true` iff the two students have the same name
 */
bool operator==(const Student& lhs, const Student& rhs);

/**
 * Test for student inequality. One student is inequal to the other if they have inequal names.
 *
 * @param lhs the one student
 * @param rhs the other student
 * @returns `true` iff the two students do not have the same name
 */
bool operator!=(const Student& lhs, const Student& rhs);

/**
 * Pretty print a Student to an output stream.
 *
 * @param os the output stream
 * @param student the student
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const Student& student);

/**
 * Item container for MyList of Student.
 *
 * @param value
 * @param next
 * @param previous
 */
struct MyNode {
    Student value;
    MyNode* next = nullptr;
    MyNode* previous = nullptr;
};

/**
 * Pretty print a MyNode to an output stream.
 *
 * @param os the output stream
 * @param node the MyNode
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const MyNode& node);

/**
 * Linked list of Student.
 */
class MyList {
 private:
    size_t _size;
    MyNode* _head;
    MyNode* _tail;

 public:
    /**
     * Construct an empty list.
     */
    MyList() : _size{0}, _head{nullptr}, _tail{nullptr} {}

    /**
     * Destructor.
     */
    ~MyList() { clear(); }

    /**
     * Default (shallow) copy constructor.
     */
    MyList(const MyList&) = default;

    /**
     * Default (shallow) copy assignment operator.
     */
    MyList& operator=(const MyList&) = default;

    /**
     * Get the number of items in the list.
     *
     * @returns the number of items in the list
     */
    size_t size() const { return _size; }

    /**
     * Test for empty list.
     *
     * @returns `true` iff the list is empty
     */
    bool empty() const { return _head == nullptr; }

    /**
     * Get a copy of the head pointer.
     *
     * @returns a copy of the head pointer
     */
    MyNode* head() const { return _head; }

    /**
     * Get a copy of the tail pointer.
     *
     * @returns a copy of the tail pointer
     */
    MyNode* tail() const { return _tail; }

    /**
     * Add an item to the end of the list.
     *
     * @param student the value to add
     */
    void add(Student student);

    /**
     * Remove all items from the list.
     */
    void clear();

    /**
     * Remove an item by value.
     *
     * @param student value to remove
     * @returns `true` iff an item was removed
     */
    bool remove(const Student& student);

    /**
     * Insert an item at the specified index
     *
     * @param student value to insert
     * @param index index at which to insert
     * @returns `true` iff the item was inserted
     */
    bool insert(Student student, size_t index);
};

/**
 * Pretty print a MyList to an output stream.
 *
 * @param os the output stream
 * @param list the MyList
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const MyList& list);
