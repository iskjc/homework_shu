//
// Created by srj15 on 2025/12/17.
//

#ifndef HOMEWORK_SHU_STRING_H
#define HOMEWORK_SHU_STRING_H

#include "VECTOR.h"
#include <cstring>
#include "exceptions.h"

class String : public VECTOR<char> {
public:
    String(const char* s = "") {
        if (s == nullptr) {
            throw NullPointerException("String constructor");
        }
        size_ = strlen(s);
        try {
            data = new char[size_];
        } catch (const std::bad_alloc&) {
            throw BadAllocException("String constructor (length=" + to_string(size_) + ")");
        }
        memcpy(data, s, size_);
    }

    String(const String& other) : VECTOR<char>(other) {}

    String& operator=(const String& other) {
        VECTOR<char>::operator=(other);
        return *this;
    }

    void resize(size_t n) override {
        if (n > 1000000) {
            throw InvalidSizeException(n, "String::resize");
        }
        char* newData = nullptr;
        try {
            newData = new char[n];
        } catch (const std::bad_alloc&) {
            throw BadAllocException("String::resize (target size=" + to_string(n) + ")");
        }
        size_t len = (n < size_) ? n : size_;
        for (size_t i = 0; i < len; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size_ = n;
    }

    String operator+(const String& rhs) const {
        if (this->data == nullptr || rhs.data == nullptr) {
            throw NullPointerException("String::operator+");
        }
        size_t total_size = this->size_ + rhs.size_;
        if (total_size > 1000000) {
            throw InvalidSizeException(total_size, "String::operator+");
        }
        String tmp;
        tmp.size_ = size_ + rhs.size_;
        try {
            tmp.data = new char[tmp.size_];
        } catch (const std::bad_alloc&) {
            throw BadAllocException("String::operator+ (total length=" + to_string(total_size) + ")");
        }
        memcpy(tmp.data, data, size_);
        memcpy(tmp.data + size_, rhs.data, rhs.size_);
        return tmp;
    }
};
#endif //HOMEWORK_SHU_STRING_H