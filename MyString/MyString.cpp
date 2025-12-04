//
// Created by srj15 on 2025/10/31.
//

#include "MyString.h"
#include <cctype>
MyString::MyString() : data(nullptr), length(0) {}
MyString::MyString(const char* str) {
    if (str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    } else {
        data = nullptr;
        length = 0;
    }
}
MyString::MyString(const MyString& other) {
    length = other.length;
    if (other.data) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    } else {
        data = nullptr;
    }
}
MyString::~MyString() {
    delete[] data;
}
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            std::strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }
    return *this;
}

size_t MyString::size() const {
    return length;
}

bool MyString::empty() const {
    return length == 0;
}

void MyString::clear() {
    delete[] data;
    data = nullptr;
    length = 0;
}

const char* MyString::c_str() const {
    return data ? data : "";
}

MyString MyString::operator+(const MyString& rhs) const {
    size_t newLen = length + rhs.length;
    char* newData = new char[newLen + 1];
    std::strcpy(newData, c_str());
    std::strcat(newData, rhs.c_str());
    MyString result(newData);
    delete[] newData;
    return result;
}

MyString& MyString::operator+=(const MyString& rhs) {
    *this = *this + rhs;
    return *this;
}

bool MyString::operator==(const MyString& rhs) const {
    return std::strcmp(c_str(), rhs.c_str()) == 0;
}

bool MyString::operator!=(const MyString& rhs) const {
    return !(*this == rhs);
}

char& MyString::operator[](size_t index) {
    return data[index];
}

const char& MyString::operator[](size_t index) const {
    return data[index];
}

int MyString::find(const char* substr) const {
    if (!substr || !data) return -1;
    const char* pos = std::strstr(data, substr);
    return pos ? static_cast<int>(pos - data) : -1;
}

void MyString::toUpper() {
    for (size_t i = 0; i < length; ++i)
        data[i] = std::toupper(static_cast<unsigned char>(data[i]));
}

void MyString::toLower() {
    for (size_t i = 0; i < length; ++i)
        data[i] = std::tolower(static_cast<unsigned char>(data[i]));
}
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.c_str();
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[1024];
    is >> buffer;
    str = MyString(buffer);
    return is;
}
