//
// Created by srj15 on 2025/12/17.
//

#ifndef HOMEWORK_SHU_VECTORR_H
#define HOMEWORK_SHU_VECTORR_H
#include "VECTOR.h"
#include <algorithm>

template <typename T>
class Vectorr : public VECTOR<T> {
public:
    using VECTOR<T>::VECTOR;
    void resize(size_t n) override {
        if (n == 0) {
            delete[] this->data;
            this->data = nullptr;
            this->size_ = 0;
            return;
        }

        T* newData = new T[n];
        size_t len = min(this->size_, n);

        for (size_t i = 0; i < len; ++i)
            newData[i] = this->data[i];
        for (size_t i = len; i < n; ++i)
            newData[i] = T();

        delete[] this->data;
        this->data = newData;
        this->size_ = n;
    }

    Vectorr operator+(const Vectorr& other) const {
        size_t n = min(this->size_, other.size_);
        Vectorr tmp(n, nullptr);
        for (size_t i = 0; i < n; ++i)
            tmp[i] = this->data[i] + other.data[i];
        return tmp;
    }
};
#endif //HOMEWORK_SHU_VECTORR_H