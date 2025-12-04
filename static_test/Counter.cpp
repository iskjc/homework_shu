//
// Created by srj15 on 2025/11/7.
//
#include <iostream>
using namespace std;
class Counter {
    public:
        Counter() {
            count++;
            id=count;
        }
        ~Counter() {}
        static void showCount(){
            cout<<count<<endl;
        }
        void showID() const{
            cout<<id<<endl;
        }
    private:
        static int count;
        int id;
};
int Counter::count=0;
int main() {
    Counter::showCount();
    Counter a,b,c;
    a.showID();
    b.showID();
    c.showID();
    Counter::showCount();

}
