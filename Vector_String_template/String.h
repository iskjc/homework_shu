//
// Created by srj15 on 2025/12/17.
//

#ifndef HOMEWORK_SHU_STRING_H
#define HOMEWORK_SHU_STRING_H

#include "VECTOR.h"
#include <cstring>

class String : public VECTOR<char> {
public:
    String(const char* s = "") {
        size_ = strlen(s);
        data = new char[size_];
        memcpy(data, s, size_);
    }

    String(const String& other) : VECTOR<char>(other) {}

    String& operator=(const String& other) {
        VECTOR<char>::operator=(other);
        return *this;
    }

    void resize(size_t n) override {
        char* newData = new char[n];
        size_t len = (n < size_) ? n : size_;
        for (size_t i = 0; i < len; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size_ = n;
    }

    String operator+(const String& rhs) const {
        String tmp;
        tmp.size_ = size_ + rhs.size_;
        tmp.data = new char[tmp.size_];
        memcpy(tmp.data, data, size_);
        memcpy(tmp.data + size_, rhs.data, rhs.size_);
        return tmp;
    }
};
#endif //HOMEWORK_SHU_STRING_H