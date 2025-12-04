#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int h, m, s;
public:
    Time(); // 默认构造
    Time(int h, int m, int s); // 构造函数

    void set_time(int h, int m, int s);
    void show_time() const;
};

#endif
