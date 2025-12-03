// provided.  do not modify. do not submit.
#include <iostream>
#include "linked_list.h"

using std::ostream;

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.name == rhs.name;
}

bool operator!=(const Student& lhs, const Student& rhs) {
    return lhs.name != rhs.name;
}

ostream& operator<<(ostream& os, const Student& student) {
    return os << student.name << ", " << student.score;
}

ostream& operator<<(ostream& os, const MyNode& node) {
    return os << "[" << node.value << "]";
}

ostream& operator<<(ostream& os, const MyList& list) {
    if (list.empty()) {
        return os << "<empty>";
    }

    MyNode* current = list.head();
    os << *current;
    current = current->next;
    while (current) {
        os << "->" << *current;
        current = current->next;
    }

    return os;
}
