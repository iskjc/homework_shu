//
// Created by srj15 on 2025/11/26.
//
#include <iostream>
using namespace std;
class Window {
protected:
    int length;
    int width;
public:
    Window(int l,int w):length(l),width(w){}
    void setLength(int l) {
        length=l;
    }
    void setWidth(int w) {
        width=w;
    }
    void getSize() {
        cout<<(length*width)<<endl;
    }
};

class MainWindow:public Window {
public:
    MainWindow(int l,int w):Window(l,w){}
    void showWindow() {
        cout<<"window size is: "<<endl;
        getSize();
    }
};
int main() {
    MainWindow mw(9,5);
    mw.showWindow();
    mw.setLength(10);
    mw.setWidth(20);
    mw.showWindow();

}