//
// Created by srj15 on 2025/10/31.
//

#ifndef HOMEWORK_SHU_MYSTRING_H
#define HOMEWORK_SHU_MYSTRING_H

#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:

    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();

    MyString& operator=(const MyString& other);

    size_t size() const;
    bool empty() const;
    void clear();
    const char* c_str() const;

    MyString operator+(const MyString& rhs) const;
    MyString& operator+=(const MyString& rhs);

    bool operator==(const MyString& rhs) const;
    bool operator!=(const MyString& rhs) const;

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    int find(const char* substr) const;

    void toUpper();
    void toLower();

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};

#endif //HOMEWORK_SHU_MYSTRING_H