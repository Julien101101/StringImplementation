// hw04f.cpp
#include "hw04.h"


// Constructors
StringType::StringType(const char *s) {
    capacity = std::strlen(s) + 1;
    buffer = new char[capacity];
    std::strcpy(buffer, s);
}

StringType::StringType(const StringType &s) {
    capacity = s.capacity;
    buffer = new char[capacity];
    std::strcpy(buffer, s.buffer);
}

StringType::StringType(StringType &&s) noexcept : buffer(s.buffer), capacity(s.capacity) {
    s.buffer = nullptr;
    s.capacity = 0;
}

// Assignment operators
StringType& StringType::operator = (const StringType &s) {
    if (this != &s) {
        delete[] buffer;
        capacity = s.capacity;
        buffer = new char[capacity];
        std::strcpy(buffer, s.buffer);
    }
    return *this;
}

StringType& StringType::operator = (StringType &&s) noexcept {
    if (this != &s) {
        delete[] buffer;
        buffer = s.buffer;
        capacity = s.capacity;
        s.buffer = nullptr;
        s.capacity = 0;
    }
    return *this;
}

// Destructor
StringType::~StringType() {
    delete[] buffer;
}

// Member functions
char& StringType::operator[] (const int index) {
    return buffer[index];
}

int StringType::length() const {
    return std::strlen(buffer);
}

int StringType::indexOf(char c) const {
    char *ptr = std::strchr(buffer, c);
    if (ptr) {
        return ptr - buffer;
    }
    return -1;
}

int StringType::indexOf(const StringType &pat) const {
    char *ptr = std::strstr(buffer, pat.buffer);
    if (ptr) {
        return ptr - buffer;
    }
    return -1;
}

bool StringType::operator==(const StringType &s) const {
    return std::strcmp(buffer, s.buffer) == 0;
}

StringType StringType::operator+(const StringType &s) const {
    StringType result;
    result.capacity = capacity + s.capacity - 1;
    result.buffer = new char[result.capacity];
    std::strcpy(result.buffer, buffer);
    std::strcat(result.buffer, s.buffer);
    return result;
}

StringType& StringType::operator+=(const StringType &s) {
    char *newBuffer = new char[capacity + s.capacity - 1];
    std::strcpy(newBuffer, buffer);
    std::strcat(newBuffer, s.buffer);
    delete[] buffer;
    buffer = newBuffer;
    capacity += s.capacity - 1;
    return *this;
}

StringType StringType::reverse() const {
    StringType result;
    result.capacity = capacity;
    result.buffer = new char[result.capacity];
    for (int i = 0; i < length(); ++i) {
        result.buffer[i] = buffer[length() - i - 1];
    }
    result.buffer[length()] = '\0';
    return result;
}

void StringType::print(std::ostream &out) const {
    out << buffer;
}

void StringType::read(std::istream &in) {
    char temp[1000]; // Arbitrary size for simplicity
    in >> temp;
    delete[] buffer;
    capacity = std::strlen(temp) + 1;
    buffer = new char[capacity];
    std::strcpy(buffer, temp);
}

// Free functions
std::ostream& operator<<(std::ostream& out, const StringType& str) {
    str.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, StringType& str) {
    str.read(in);
    return in;
}

StringType copyConstructorTest(StringType l) {
    return l;
}

void testReverse() {
    std::ifstream in("input.txt");
    if (!in) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return;
    }
    StringType l;

    while (in >> l) {
        StringType copied = copyConstructorTest(l); // Test the copy constructor
        std::cout << "Original: " << l
                  << ", Copied: " << copied
                  << ", Length: " << l.length()
                  << ", Reverse: " << l.reverse() << std::endl;
    }
}

void testDefaultConstructor() {
    StringType str; // Test default constructor
    std::cout << "Default Constructor: \"" << str << "\", Length: " << str.length() << std::endl;
}

void testParameterizedConstructor() {
    StringType str("Hello"); // Test parameterized constructor
    std::cout << "Parameterized Constructor: \"" << str << "\", Length: " << str.length() << std::endl;
}

void testCopyConstructor() {
    StringType original("Hello");
    StringType copy(original); // Test the copy constructor
    std::cout << "Original: \"" << original << "\", Copy: \"" << copy << "\", Length: " << copy.length() << std::endl;
}

void testMoveConstructor() {
    StringType original("Hello");
    StringType moved(std::move(original)); // Test the move constructor
    std::cout << "Moved: \"" << moved << "\", Length: " << moved.length() << std::endl;
}

void testCopyAssignmentOperator() {
    StringType str1("Hello");
    StringType str2;
    str2 = str1; // Test the copy assignment operator
    std::cout << "str1: \"" << str1 << "\", str2: \"" << str2 << "\", Length: " << str2.length() << std::endl;
}

void testMoveAssignmentOperator() {
    StringType str1("Hello");
    StringType str2;
    str2 = std::move(str1); // Test the move assignment operator
    std::cout << "str2: \"" << str2 << "\", Length: " << str2.length() << std::endl;
}

void testIndexOperator() {
    StringType str("Hello");
    str[0] = 'h'; // Test the index operator
    std::cout << "Modified String: \"" << str << "\", First Character: " << str[0] << std::endl;
}

void testIndexOf() {
    StringType str("Hello World");
    int index = str.indexOf('W'); // Test indexOf for a single character
    std::cout << "Index of 'W': " << index << std::endl;
    
    int subIndex = str.indexOf("World"); // Test indexOf for a substring
    std::cout << "Index of \"World\": " << subIndex << std::endl;
}

void testEqualityOperator() {
    StringType str1("Hello");
    StringType str2("Hello");
    StringType str3("World");
    std::cout << "str1 == str2: " << (str1 == str2 ? "True" : "False") << std::endl;
    std::cout << "str1 == str3: " << (str1 == str3 ? "True" : "False") << std::endl;
}

void testAdditionOperator() {
    StringType str1("Hello");
    StringType str2(" World");
    StringType result = str1 + str2; // Test the + operator
    std::cout << "Concatenated String: \"" << result << "\", Length: " << result.length() << std::endl;
}

void testAdditionAssignmentOperator() {
    StringType str1("Hello");
    StringType str2(" World");
    str1 += str2; // Test the += operator
    std::cout << "After Addition Assignment: \"" << str1 << "\", Length: " << str1.length() << std::endl;
}

void testReverseMethod() {
    StringType str("Hello");
    StringType reversed = str.reverse(); // Test the reverse method
    std::cout << "Reversed String: \"" << reversed << "\", Length: " << reversed.length() << std::endl;
}

void testPrintMethod() {
    StringType str("Hello");
    std::cout << "Print Method Output: ";
    str.print(std::cout); // Test the print method
    std::cout << std::endl;
}

void testReadMethod() {
    std::ofstream out("input.txt");
    out << "Hello World";
    out.close();
    
    StringType str;
    std::ifstream in("input.txt");
    str.read(in); // Test the read method
    in.close();
    
    std::cout << "Read Method Output: \"" << str << "\", Length: " << str.length() << std::endl;
}
