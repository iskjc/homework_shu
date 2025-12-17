//
// Created by srj15 on 2025/12/17.
//
#include <iostream>
#include <cmath>
#include "Vectorr.h"
#include "String.h"

using namespace std;

void testString() {
    String str1 = "Hello", str2 = str1, str3;
    cout << "str1 = \"" << str1
         << "\"\nstr2 = \"" << str2
         << "\"\nstr3 = \"" << str3 << "\"" << endl;
    str3 = str2;
    str1 = "C++ program.";
    str2 = str3 + ", world!";

    cout << "str1 = \"" << str1
         << "\"\nstr2 = \"" << str2
         << "\"\nstr3 = \"" << str3 << "\"" << endl;
    cout << "\n清除对象的数据..." << endl;
    str1.resize(0);
    str2.resize(0);
    str3.resize(0);
    cout << "str1 = \"" << str1
         << "\"\nstr2 = \"" << str2
         << "\"\nstr3 = \"" << str3 << "\"" << endl;
}
void testVector() {
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    double x[8];
    for (int i = 0; i < 8; ++i)
        x[i] = sqrt(double(i));

    Vectorr<int> vi1(10, a), vi2(5, a + 5);
    Vectorr<double> vd1(8, x), vd2(3, x);

    cout << "原始数据：" << endl;
    cout << "vi1 = " << vi1 << "\nvi2 = " << vi2
         << "\nvd1 = " << vd1 << "\nvd2 = " << vd2 << endl;

    cout << "\n调整维数到5：" << endl;
    vi1.resize(5);
    vi2.resize(5);
    vd1.resize(5);
    vd2.resize(5);

    cout << "vi1 = " << vi1 << "\nvi2 = " << vi2
         << "\nvd1 = " << vd1 << "\nvd2 = " << vd2 << endl;

    cout << "\nvi1 + vi2 = " << vi1 + vi2
         << "\nvd1 + vd2 = " << vd1 + vd2 << endl;
}
