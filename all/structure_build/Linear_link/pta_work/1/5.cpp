#include <iostream>
#include <iomanip>
using namespace std;
struct node{
    int id;
    node *ne;
};
typedef pair <node*,node*> PII;
PII build(int m){
    node * h=nullptr,*pre,*cur,*t;
    for (int i=1;i<=m;i++){
        cur=new node;
        cur->id=i;
        cur->ne=nullptr;
        if (i==1)    h=cur;
        else    pre->ne=cur;
        pre=cur;
    }
    t=cur;cur->ne=h;//末尾
    return {h,t};
}
//也可以一开始就让自己指向自己，然后不断插入成环
int main(){
    int m,n;
    cin>>m>>n;
    PII t=build(m);
    node *cur=t.first,*pre=t.second;
    int cnt=0;
    while (cur->ne!=cur){
        cnt++;
        if (cnt==n)    pre->ne=cur->ne,cnt=0,cout<<setw(4)<<cur->id,cur=pre->ne;
        else    pre=cur,cur=pre->ne;
    }
    cout<<setw(4)<<cur->id;//最后的
}