#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415
class Shape{
    public:
    float h,w,r;
    Shape(float h,float w): h(h),w(w){}
    Shape(float r): r(r){}
    virtual float getArea()=0;//纯虚函数声明
};
class Circle:public Shape{
    public:
    Circle(float r):Shape(r){}
    float getArea(){
        return PI*r*r;//注意无法继承父类的私有属性
    }
};
class Rectangle:public Shape{
    public:
    Rectangle(float h,float w):Shape(h,w){}
    float getArea(){
        return h*w;
    }
};
class Triangle:public Shape{
    public:
    Triangle(float h,float w):Shape(h,w){}
    float getArea(){
        return h*w/2;
    }
};
void show(Shape& fe){
    cout<<fixed<<setprecision(2)<<fe.getArea()<<"\n";
}
int main(){
    float r,h1,w1,h2,w2;
    cin>>r>>h1>>w1>>h2>>w2;
    Circle a1(r);
    Rectangle a2(h1,w1);
    Triangle a3(h2,w2);
    show(a1),show(a2),show(a3);
}