#include "Time.h"

int main() {
    Time t1, t2;

    int h, m, s;
    cin >> h >> m >> s;
    t1.set_time(h, m, s);
    cin >> h >> m >> s;
    t2.set_time(h, m, s);

    cout << "Time t1: ";
    t1.show_time();

    cout << "Time t2: ";
    t2.show_time();

    return 0;
}
