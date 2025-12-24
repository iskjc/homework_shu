//
// Created by srj15 on 2025/12/24.
//

#ifndef HOMEWORK_SHU_EXCEPTIONS_H
#define HOMEWORK_SHU_EXCEPTIONS_H
#include <exception>
#include <string>

class OutOfRangeException : public std::exception {
private:
    std::string msg;
public:
    OutOfRangeException(size_t index, size_t max_size) {
        msg = "Index out of range: " + std::to_string(index)
              + " (max valid index: " + std::to_string(max_size - 1) + ")";
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class BadAllocException : public std::exception {
private:
    std::string msg;
public:
    BadAllocException(const std::string& context) {
        msg = "Memory allocation failed: " + context;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class InvalidSizeException : public std::exception {
private:
    std::string msg;
public:
    InvalidSizeException(size_t size, const std::string& context) {
        msg = "Invalid size " + std::to_string(size) + " in " + context;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class NullPointerException : public std::exception {
private:
    std::string msg;
public:
    NullPointerException(const std::string& context) {
        msg = "Null pointer access in " + context;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class InvalidStringException : public std::exception {
private:
    std::string msg;
public:
    InvalidStringException(const std::string& context) {
        msg = "Invalid string operation: " + context;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

#endif //HOMEWORK_SHU_EXCEPTIONS_H