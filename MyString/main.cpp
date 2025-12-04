#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3(s1);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 (拷贝自 s1) = " << s3 << endl;

    s3 = s2;
    cout << "s3 = s2 后: " << s3 << endl;

    MyString s4 = s1 + MyString(", ") + s2;
    cout << "拼接结果 s4 = " << s4 << endl;

    cout << "s1 == s2 ? " << (s1 == s2) << endl;
    cout << "s1 != s2 ? " << (s1 != s2) << endl;

    cout << "s4 中查找 \"World\" 位置: " << s4.find("World") << endl;

    s4.toUpper();
    cout << "大写: " << s4 << endl;
    s4.toLower();
    cout << "小写: " << s4 << endl;

    cout << "s1[1] = " << s1[1] << endl;

    s1.clear();
    cout << "清空后 s1 是否为空: " << s1.empty() << endl;
    return 0;
}
