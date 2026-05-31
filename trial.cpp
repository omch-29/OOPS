#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual double area(){
        cout<<"area";
    }
    void getshape(){
        cout<<"this is shape";
    }
};
class Circle : public Shape{
public:
    double area(){
        cout<<3.14*5*5;
    }
};

int main(){
    Circle c;
    c.getshape();
}