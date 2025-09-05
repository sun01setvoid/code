#include <iostream>
using namespace std;
class A{
    protected :
    int i;
    public:
    A(int i): i(i){cout<<"Call A:i="<<i<<"\n";}
    void display(){cout<<i<<"\n";}
};
class A1: virtual public A{
    protected :
    int j;
    public:
    A1(int i,int j): A(i),j(j){cout<<"Call A1:i="<<i<<"\n";}
};
class A2: virtual public A{
    protected :
    int k;
    public:
    A2(int i,int k): A(i),k(k){cout<<"Call A2:i="<<i<<"\n";}
};
class A3:public A1,public A2{
    public:
    A3(int i,int j,int k):A1(i,j),A2(i,k),A(i){cout<<"Call A3:i="<<i<<"\n";}
    void disp(){cout<<"i="<<i<<"\nj="<<j<<"\nk="<<k;}
};
int main(){
    int i,j,k;
    cin>>i>>j>>k;
    A3 p(i,j,k);
    p.disp();
}