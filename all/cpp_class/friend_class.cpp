#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point{
    private:
        double x,y;
    public:
        Point();
        Point(double x_,double y_);
        double distance();
        double distance(const Point &p);//这个没用啊
        double getX() {return x;}
        double getY(){return y;}
        void setX(double x_);
        void setY(double y_);
};
Point::Point(double x_,double y_){x=x_;y=y_;}
void Point::setX(double x_){x=x_;}
void Point::setY(double y_){x=y_;}
double Point::distance(){return sqrt(x*x+y*y);}

class Circle{
    Point* ptr;
    double r;
    public:
    Circle(){}
    Circle(Point &p,double ri){
        ptr=new Point(p);
        r=ri;
    }
    string judge(Point &p){
        string tmp;
        double d=sqrt((p.getX()-ptr->getX())*(p.getX()-ptr->getX())+(p.getY()-ptr->getY())*(p.getY()-ptr->getY()));
        if (abs(r-d)<1e-6)   tmp="on";
        else if (r<d)    tmp="outside";
        else    tmp="inside";
        return tmp;
    }
};
int main()
{
   double x1,y1,x2,y2,r; 
   cin>>x1>>y1>>x2>>y2>>r;
   Point p(x1,y1);
   Point ctr(x2,y2);
   Circle c(ctr,r);
   cout<<setprecision(3)<<p.distance()<<" "<<c.judge(p)<<endl;
} 