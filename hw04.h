// hw04.h
#ifndef HW04_H
#define HW04_H


#include <iostream>
#include <fstream>
#include <cstring>


class StringType {
public:
    StringType(const char *s = "");
    StringType(const StringType &s);
    StringType(StringType &&s) noexcept;
    StringType& operator = (const StringType &s);
    StringType& operator = (StringType &&s) noexcept;
    char& operator[] (const int index);
    int length() const;
    int indexOf(char c) const;
    int indexOf(const StringType &pat) const;
    bool operator==(const StringType &s) const;
    StringType operator+(const StringType &s) const;
    StringType& operator+=(const StringType &s);
    StringType reverse() const;
    void print(std::ostream &out) const;
    void read(std::istream &in);
    ~StringType();

private:
    char* buffer;
    int capacity;
};

std::ostream& operator<<(std::ostream& out, const StringType& str);
std::istream& operator>>(std::istream& in, StringType& str);
StringType copyConstructorTest(StringType l);
void testReverse();

    void testDefaultConstructor();
    void testParameterizedConstructor();
    void testCopyConstructor();
    void testMoveConstructor();
    void testCopyAssignmentOperator();
    void testMoveAssignmentOperator();
    void testIndexOperator();
    void testIndexOf();
    void testEqualityOperator();
    void testAdditionOperator();
    void testAdditionAssignmentOperator();
    void testReverse();
    void testPrintMethod();
    void testReadMethod();

#endif // HW04_H