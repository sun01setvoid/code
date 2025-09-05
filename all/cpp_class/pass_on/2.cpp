#include <iostream>
#include<iomanip>
using namespace std;
const double PI=3.14;
class Dot{
    float x,y;
    public:
    Dot(float x,float y):x(x),y(y)//this指针不能写在这里,且这边不能用=，一定要用（）,这里是初始化的地方，所以知道x,y是什么
    {
        //this->x=x,this->y=y;这里要写this,不然不知道是哪一个
        cout<<"Dot constructor called\n";
    }
    ~Dot(){
        cout<<"Dot destructor called\n";
    }
};
class Cir : public Dot{
    float r;
    public:
    Cir(float x,float y,float r):Dot(x,y),r(r){
        //this->r=r;
        cout<<"Cir constructor called\n";}
    float getArea(){
        return PI*r*r;
    }
    ~Cir(){cout<<"Cir destructor called\n";}
};
int main(){
    float x,y,r;
    cin>>x>>y>>r;
    Cir c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
    return 0;
}