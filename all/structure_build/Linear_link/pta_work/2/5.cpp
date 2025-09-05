#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int stk[1010],q[1010];
    int top=-1,hh=0,tt=-1;
    int tmp;
    while (cin>>tmp){
        if (tmp>0)    stk[++top]=tmp;
        else if (tmp<0)    q[++tt]=tmp;
    }
    while (top!=-1)    cout<<setw(5)<<stk[top--];
    cout<<endl;
    while (hh<=tt)    cout<<setw(5)<<q[hh++];
    cout<<endl;
}