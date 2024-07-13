// Julien Savary
//hw04.cpp
#include "hw04.h"

int main() {
    // Create an original StringType object
    StringType original("Hello");

    // Create a new StringType object using the copy constructor
    StringType copy(original);

    // Check if the copy has the same content as the original
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;

    // Check if they are different objects
    if (&original != &copy) {
        std::cout << "Copy constructor works: original and copy are different objects." << std::endl;
    } else {
        std::cout << "Copy constructor failed: original and copy are the same object." << std::endl;
    }
    testDefaultConstructor();
    testParameterizedConstructor();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignmentOperator();
    testMoveAssignmentOperator();
    testIndexOperator();
    testIndexOf();
    testEqualityOperator();
    testAdditionOperator();
    testAdditionAssignmentOperator();
    testReverse();
    testPrintMethod();
    testReadMethod();
    return 0;
}