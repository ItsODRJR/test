// provided.  you may modify.  do not submit.
#include <iostream>
#include <sstream>
#include <string>
#include "linked_list.h"

#define expect_true(actual) \
if (!(actual)) {\
    std::cout << "[FAIL] " << __FILE__ << ":" << __LINE__ << ": " << __func__ << ": expect_true(" << #actual << ") failed" << '\n';\
    std::cout << "[FAIL] " << actual << " is false" << std::endl;\
}

#define expect_equal(actual, expected) \
if (!(actual == expected)) {\
    std::cout << "[FAIL] " << __FILE__ << ":" << __LINE__ << ": " << __func__ << ": expect_equal(" << #actual << ", " << #expected << ") failed" << '\n';\
    std::cout << "[FAIL] expected " << expected << '\n';\
    std::cout << "[FAIL]      got " << actual << std::endl;\
}

#define expect_contains(list, expected_size, expected_output) \
{\
    expect_equal(list.size(), expected_size);\
    std::ostringstream stream;\
    stream << list;\
    std::string output = stream.str();\
    expect_equal(output, expected_output);\
}

#define expect_empty(list) \
{\
    expect_true(list.empty());\
    expect_equal(list.head(), nullptr);\
    expect_contains(list, 0, "<empty>");\
}

int main() {
    // Given an empty list
    MyList list;

    // Then the list should be empty
    expect_empty(list);

    // When I add the following values:
    //     | name  | score |
    //     | Alice | 86    |
    //     | Bob   | 75    |
    //     | Dave  | 9     |
    list.add({"Alice", 86});
    list.add({"Bob", 75});
    list.add({"Dave", 9});

    // Then the list should contain 3 items: [Alice, 86]->[Bob, 75]->[Dave, 9]
    expect_contains(list, 3, "[Alice, 86]->[Bob, 75]->[Dave, 9]");

    // When I insert {"Carol", 30} at index 2
    list.insert({"Carol", 30}, 2);

    // Then the list should contain 4 items: [Alice, 86]->[Bob, 75]->[Carol, 30]->[Dave, 9]
    expect_contains(list, 4, "[Alice, 86]->[Bob, 75]->[Carol, 30]->[Dave, 9]");

    // When I remove {"Bob"}
    list.remove({"Bob"});

    // Then the list should contain 3 items: [Alice, 86]->[Carol, 30]->[Dave, 9]
    expect_contains(list, 3, "[Alice, 86]->[Carol, 30]->[Dave, 9]");

    // When I clear the list
    list.clear();

    // Then the list should be empty
    expect_empty(list);
}
