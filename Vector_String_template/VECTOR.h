//
// Created by srj15 on 2025/12/17.
//

#ifndef HOMEWORK_SHU_VECTOR_H
#define HOMEWORK_SHU_VECTOR_H
#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
class VECTOR {
protected:
    T* data;
    size_t size_;

public:
    VECTOR() : data(nullptr), size_(0) {}

    VECTOR(size_t n, const T* arr) : size_(n) {
        data = new T[n];
        for (size_t i = 0; i < n; ++i)
            data[i] = arr[i];
    }

    VECTOR(const VECTOR& other) : size_(other.size_) {
        data = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data[i] = other.data[i];
    }

    VECTOR& operator=(const VECTOR& other) {
        if (this == &other) return *this;
        delete[] data;
        size_ = other.size_;
        data = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data[i] = other.data[i];
        return *this;
    }

    virtual ~VECTOR() {
        delete[] data;
    }

    virtual void resize(size_t n) = 0;

    size_t size() const { return size_; }

    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_t i) const { return data[i]; }
};

template <typename T>
ostream& operator<<(ostream& os, const VECTOR<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

template <typename T>
istream& operator>>(istream& is, VECTOR<T>& v) {
    for (size_t i = 0; i < v.size(); ++i)
        is >> v[i];
    return is;
}

#endif //HOMEWORK_SHU_VECTOR_H