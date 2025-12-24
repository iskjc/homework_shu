//
// Created by srj15 on 2025/12/17.
//

#ifndef HOMEWORK_SHU_VECTORR_H
#define HOMEWORK_SHU_VECTORR_H
#include "VECTOR.h"
#include <algorithm>
#include "exceptions.h"
template <typename T>
class Vectorr : public VECTOR<T> {
public:
    using VECTOR<T>::VECTOR;
    void resize(size_t n) override {
        if (n > 1000000) {
            throw InvalidSizeException(n, "Vectorr::resize");
        }

        if (n == 0) {
            delete[] this->data;
            this->data = nullptr;
            this->size_ = 0;
            return;
        }

        try {
            newData = new T[n];
        } catch (const std::bad_alloc&) {
            throw BadAllocException("Vectorr::resize (target size=" + to_string(n) + ")");
        }
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
        if (n == 0) {
            throw InvalidStringException("Vectorr::operator+ (empty vectors)");
        }
        Vectorr tmp(n, nullptr);
        for (size_t i = 0; i < n; ++i)
            tmp[i] = this->data[i] + other.data[i];
        return tmp;
    }
};
#endif //HOMEWORK_SHU_VECTORR_H