//
// Created by srj15 on 2025/12/17.
//
#include <iostream>
#include <cmath>
#include "Vectorr.h"
#include "String.h"
#include "exceptions.h"

using namespace std;

void testString() {
    cout << "===== Test String =====" << endl;

    try {
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

    } catch (const exception& e) {
        cout << "[String Test Exception] " << e.what() << endl;
    }

    cout << endl;
}

void testVector() {
    cout << "===== Test Vectorr =====" << endl;

    try {
        int a[10] = {10,9,8,7,6,5,4,3,2,1};
        double x[8];

        for (int i = 0; i < 8; ++i)
            x[i] = sqrt(static_cast<double>(i));

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

        cout << "\n测试越界访问：vi1[10] = " << vi1[10] << endl;

    } catch (const OutOfRangeException& e) {
        cout << "[Vectorr OutOfRange Exception] " << e.what() << endl;
    } catch (const BadAllocException& e) {
        cout << "[Vectorr BadAlloc Exception] " << e.what() << endl;
    } catch (const InvalidSizeException& e) {
        cout << "[Vectorr InvalidSize Exception] " << e.what() << endl;
    } catch (const exception& e) {
        cout << "[Vectorr Other Exception] " << e.what() << endl;
    }

    cout << endl;
}

void testExceptionScenarios() {
    cout << "===== Test Exception Scenarios =====" << endl;

    try {
        Vectorr<int> v;
        v.resize(2000000);
    } catch (const exception& e) {
        cout << "[Test 1] " << e.what() << endl;
    }

    try {
        String s1("a");
        String s2;
        String s3 = s1 + s2;

        String s4;
        String s5 = s4 + s4;
    } catch (const exception& e) {
        cout << "[Test 2] " << e.what() << endl;
    }

    cout << endl;
}
