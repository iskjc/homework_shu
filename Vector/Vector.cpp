//
// Created by srj15 on 2025/11/7.
//
#include <iostream>
using namespace std;

class Vector {
private:
    int n;
    double *x;

public:
    Vector(int dimension = 0) : n(dimension) {
        if (n > 0)
            x = new double[n];
        else
            x = nullptr;
    }
    Vector(const Vector &vec) {
        n = vec.n;
        if (n > 0) {
            x = new double[n];
            for (int i = 0; i < n; ++i)
                x[i] = vec.x[i];
        } else {
            x = nullptr;
        }
    }
    Vector &operator=(const Vector &vec) {
        if (this != &vec) {
            delete[] x;
            n = vec.n;
            if (n > 0) {
                x = new double[n];
                for (int i = 0; i < n; ++i)
                    x[i] = vec.x[i];
            } else {
                x = nullptr;
            }
        }
        return *this;
    }
    virtual ~Vector() {
        delete[] x;
    }
    void Set() {
        if (n <= 0) return;
        cout << "请输入" << n << "维向量的各个分量: ";
        for (int i = 0; i < n; ++i)
            cin >> x[i];
    }
    int Getdim() const { return n; }
    void show() const {
        cout << "(";
        for (int i = 0; i < n; ++i) {
            cout << x[i];
            if (i < n - 1) cout << ", ";
        }
        cout << ")" << endl;
    }
};
int main() {
    Vector v1(3);
    v1.Set();
    v1.show();

    Vector v2 = v1;
    v2.show();

    Vector v3;
    v3 = v1;         // 赋值运算符
    v3.show();

    cout << "维度: " << v3.Getdim() << endl;
    return 0;
}
