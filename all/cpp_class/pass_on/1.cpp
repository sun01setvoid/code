#include <iostream>
#include<iomanip>
using namespace std;
#include <cmath>
#define pi 3.14
class Point{
    float x,y;
    public:
        Point (int x,int y){
            cout<<"Point constructor called"<<"\n";
        }
        Point(){ }
        ~Point(){
            cout<<"Point destructor called\n";
        }
};
class Circle :public Point{
    float r;
    public:
        Circle (int x,int y,int r):Point(x,y){
            //如果Point(x,y)写在这里，那么会创建两个Point,前面一个是默认构造(因为没传参)
            cout<<"Circle constructor called"<<"\n";
            this->r=r;
        }
        float getCircumference(){
            return pi*2*r;
        }
        ~Circle(){
            cout<<"Circle destructor called"<<"\n";
        }
};
int main()
{
    float x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getCircumference()<<endl;
    return 0;
}