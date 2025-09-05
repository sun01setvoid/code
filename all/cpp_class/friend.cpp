#include <iostream>
using namespace std;
class Complex{
    double x;
    double y;
    public:
    Complex(double xi=0,double yi=0):x(xi),y(yi){}
    Complex Opposite(){Complex tmp(-x,-y);return tmp;}
    void Print(){
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }
    friend Complex add( const Complex &a, const Complex&b);
};
Complex add(const Complex &a,const Complex&b){
    Complex tmp(a.x+b.x,a.y+b.y);
    return tmp;
}
int main(){
    double x,y,a,b;
    cin>>x>>y>>a>>b;
    Complex c1(x,y),c2(a,b),tmp;
    add(c1,c2).Print();
    tmp=add(c2.Opposite(),c1);
    tmp.Print();
    c2.Print();
}