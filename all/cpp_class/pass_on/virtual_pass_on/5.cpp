#include <iostream>
using namespace std;
class A{
    protected :
    int i;
    public:
    A(int i): i(i){cout<<"Call A:i="<<i<<"\n";}
    A(){};
    void display(){cout<<i<<"\n";}
};
class A1:virtual public A{
    protected :
    int j;
    public:
    A1(int x,int y): A(10),j(y){cout<<"Call A1:i="<<i<<"\n";}
};
class A2:virtual public A{
    protected :
    int k;
    public:
    A2(int x,int y):A(10),k(y){cout<<"Call A2:i="<<i<<"\n";}
};
class A3:public A1,public A2{
    public:
    A3(int x,int y,int z):A1(x,y),A2(x,z),A(x){cout<<"Call A3:i="<<i<<"\n";}
    void disp(){cout<<"j="<<j<<"\nk="<<k;}
};
//先构造虚基类，其实也是为了保证虚基类一致，因为万一B,C的构造虚基类不同,所以会忽略B,C的构造函数 
int main(){
    int i,j,k;
    cin>>i>>j>>k;
    A3 p(i,j,k);
    p.disp();
}