#include <iostream>
using namespace std;
//=1个引用是拷贝赋值,除非重载或是引用
class Myclass{
    int num;
    int s;
};
int main(){
    int a=10;
    int &b=a;
    int c=b;
    Myclass d,&p=d;
    cout<<c;
}