#include "SolveEquations.h"

SolveEquations::SolveEquations(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void SolveEquations::solve() const {
    double delta = b * b - 4 * a * c;

    if (a == 0) {
        if (b == 0) {
            cout << "NO solution" << endl;
        } else {
            double solution = -c / b;
            cout << "x=" << solution << endl;
        }
    } else {
        if (delta == 0.0) {
            double solution = -0.5 * b / a;
            cout << "x=" << solution << endl;
        } else if (delta > 0) {
            double x1 = 0.5 * (-b + sqrt(delta)) / a;
            double x2 = 0.5 * (-b - sqrt(delta)) / a;
            cout << "x1=" << x1 << " x2=" << x2 << endl;
        } else {
            double x_r = -0.5 * b / a;
            double x_i = 0.5 * sqrt(-delta) / a;
            cout << "x1=" << x_r << "+" << x_i << "i"
                 << " x2=" << x_r << "-" << x_i << "i" << endl;
        }
    }
}
