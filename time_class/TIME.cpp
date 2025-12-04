#include "Time.h"

Time::Time() : h(0), m(0), s(0) {}

Time::Time(int h, int m, int s) {
    set_time(h, m, s);
}

void Time::set_time(int hour, int min, int sec) {
    h = (hour >= 0 && hour < 24) ? hour : 0;
    m = (min >= 0 && min < 60) ? min : 0;
    s = (sec >= 0 && sec < 60) ? sec : 0;
}

void Time::show_time() const {
    cout << (h < 10 ? "0" : "") << h << ":"
         << (m < 10 ? "0" : "") << m << ":"
         << (s < 10 ? "0" : "") << s << endl;
}
