#include <iostream>
using namespace std;
class A{
private:
    int x,y;
public:
    void ask1(int a=0,int b=0);
    int ask2();
    int ask3();
};
void A::ask1(int a,int b){x=a;y=b;}
int A::ask2()
{
    if(x>y) return x;
    else return y;
}
int A::ask3(){cout<<"x="<<x<<",y="<<y<<endl;}
int main()
{
    A a;
    a.ask1();
    a.ask3();
    cout<<a.ask2()<<endl;;
    a.ask1(3,5);
    a.ask3();
    cout<<a.ask2()<<endl;
}