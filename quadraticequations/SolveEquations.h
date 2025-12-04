#ifndef SOLVE_EQUATIONS_H
#define SOLVE_EQUATIONS_H

#include <iostream>
#include <cmath>
using namespace std;

class SolveEquations {
private:
    double a, b, c;

public:
    SolveEquations(double a = 0, double b = 0, double c = 0); // 构造函数
    void solve() const;                                        // 求解函数
};

#endif
