//
// Created by srj15 on 2025/11/26.
//
#include<iostream>
using namespace std;

class Shape{
protected:
    double area;
public:
    Shape(double a=0.0):area(a){}
    double getArea(){return area;}
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r=0.0):radius(r) {}

    void setRadius(double r){ radius = r; }
    double getRadius(){ return radius; }

    void calcArea(){
        area = 3.14 * radius * radius;
    }
};
int main(){
    Circle c1;
    c1.setRadius(3.0);
    cout << "Radius = " << c1.getRadius() << endl;
    c1.calcArea();
    cout << "Area of Circle: " << c1.getArea() << endl;
    return 0;
}
