//
// Created by srj15 on 2025/11/26.
//
#include <iostream>
using namespace std;
class Currency {
private:
    double usd;
public:
    Currency(double money):usd(money){}
    double getCurrency() {
        return usd;
    }
};

class RMB:public Currency {
public:
    RMB(double money):Currency(money){}
    void getrmb() {
        cout<<(getCurrency()/7)<<endl;
    }
};
int main() {
    RMB u(10);
    u.getrmb();
}