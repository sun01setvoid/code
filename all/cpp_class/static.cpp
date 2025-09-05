#include <iostream>
using namespace std;
class People {
    string name;
    int age=1,h,w;
    public:
    static int num;//类内声明，类外定义,const的类内初始化(但不一定算的定义，看编译器)(constexpr可以，这是编译期计算)
    People(){}
    People(string a,int b,int c,int d):name(a),age(b),h(c),w(d){num++;}
    static void show(){cout<<num;}
}arr[100];
int People::num=0;
int main(){
    string name;
    int age,h,w;
    while (cin>>name){
        if (name=="exit")    break;
        cin>>age>>h>>w;
        arr[People::num]=People(name,age,h,w);
    }
    People::show();
}