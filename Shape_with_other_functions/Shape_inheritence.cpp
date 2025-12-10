//
// Created by srj15 on 2025/12/3.
//
#include<iostream>
#include<cstring>
using namespace std;
class MyString{
private:
    int len;
    char* str_buf;
public:
    MyString(char* str="default"):len(strlen(str)){
        str_buf = new char[len + 1];
        strcpy(str_buf, str);
        cout << "str = " << str_buf << this << endl;
    }
    MyString(const MyString& other) : len(other.len) {
        str_buf = new char[len + 1];
        strcpy(str_buf, other.str_buf);
        cout << "str = " << str_buf << endl;
    }
    ~MyString() {
        cout << "str = " << str_buf << this << endl;
        delete[] str_buf;
    }
    const char* getstr() const { return str_buf; }
};
class Point{
private:
    int x_val;
    int y_val;
public:
    Point(int x=0,int y=0):x_val(x),y_val(y){
            cout<<"x_val="<<x_val<<"y_val="<<y_val<<endl;
    }
    ~Point(){cout<<"I forgot what i writtrn here"<<endl;}
    int getX(){
        return x_val;
    }
    int getY(){
        return y_val;
    }

};
class Shape{
protected:
    char color;
    MyString object_ID;
public:
    Shape(char c='w',char* id="000"):color(c),object_ID(id){
        cout<<"  color ="<<color<<"  id ="<<object_ID.getstr()<<endl;
    }
    virtual ~Shape(){
        cout<<"destructor: color ="<<color<<"  id ="<<object_ID.getstr()<<endl;
    }
    virtual void show(){
        cout<<"  color ="<<color<<"  id ="<<object_ID.getstr()<<endl;
    }
};
class Circle : public Shape {
private:
    double radius;
    Point center;
public:
    Circle(double r=0.0,char c='w',char* id="000",int x=0,int y=0):radius(r),Shape(c,id),center(x,y){
        cout<<"virtual r="<<radius<<"  color ="<<color<<"  id ="<<object_ID.getstr()<<"  x ="<<center.getX()<<"  y ="<<center.getY()<<endl;
        }
    ~Circle() {cout<<"destructor: virtual r="<<radius<<"  color ="<<color<<"  id ="<<object_ID.getstr()<<"  x ="<<center.getX()<<"  y ="<<center.getY()<<endl;
    }

    void setRadius(double r){ radius = r; }
    double getRadius(){ return radius; }
    void show() override{
        cout<<"virtual r="<<radius<<"  color ="<<color<<"  id ="<<object_ID.getstr()<<"  x ="<<center.getX()<<"  y ="<<center.getY()<<endl;
    }

    double calcArea(){
        return (3.14 * radius * radius);
    }
};
void show_by_value(Shape obj){
    cout<<"value =";
    obj.show();
}

void show_by_pointer(Shape* obj) {
    cout<<"pointer =";
    obj->show();
}

void show_by_reference(Shape& obj) {
    cout<<"reference =";
    obj.show();
}

int main(){
    Circle c1(3.0,'r',"001",3,4);
    c1.show();
    show_by_pointer(&c1);
    show_by_pointer(&c1);
    show_by_reference(c1);
    c1.setRadius(10);
    cout << "Radius = " << c1.getRadius() << endl;
    c1.show();
    cout<<"area="<<c1.calcArea()<<endl;
    Shape * p=new Circle(7.0,'r',"002",5,6);
    delete p;
    return 0;
}
