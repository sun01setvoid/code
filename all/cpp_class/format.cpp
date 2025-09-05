#include <iostream>
#include <iomanip>
using namespace std;
class Date{
    int y,m,d;
    public:
    Date(int a=0,int b=0,int c=0):y(a),m(b),d(c){cout<<this->y<<"hhhh";}//创建之后就可以用this了，:里不可以用
    void print(){
        cout<<setw(4)<<setfill('0')<<y<<"-"<<setw(2)<<setfill('0')<<m<<"-"<<setw(2)<<setfill('0')<<d<<endl;
    }
};
int main(){
    int y,m,d;
    cin>>y>>m>>d;
    Date tmp(y,m,d);
    tmp.print();
}