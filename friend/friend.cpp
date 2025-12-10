//
// Created by srj15 on 2025/11/7.
//
#include <iostream>
using namespace std;
class A;
class B {
    public:
        void showA(const A&a);
};
class A {
    private:
        int secret;
    public:
        A(int s=0):secret(s){};
        friend void B::showA(const A&a);
};
void B::showA(const A& a) {
    cout<<"secret:"<<a.secret<<endl;
}
int main() {
    A a(2);
    B b;
    b.showA(a);
}
''