#include <iostream>
#include <cstdio>
using namespace std;
typedef pair <int,int> PII;
struct Node{
    int v;
    int next;
};
Node a[100010];
Node b[100010];
PII res[100];
int main(){
    int h,n,t;
    int ad,dat,ne;
    cin>>h>>n;
    for (int i=1;i<=n;i++){
        cin>>ad>>dat>>ne;
        a[ad].v=dat;
        a[ad].next=ne;
        if (ne==-1) t=ad;
    }
    int cnt=0,p2=h;
    while (p2!=-1){
        res[++cnt].first=p2;
        res[cnt].second=a[p2].v;
        p2=a[p2].next;
    }
    for (int i=1;i<=cnt/2;i++){
        if (i!=1)    b[res[i-1].first].next=res[cnt-i+1].first;
        b[res[cnt-i+1].first].next=res[i].first;
        b[res[cnt-i+1].first].v=res[cnt-i+1].second;
        b[res[i].first].next=-1;
        b[res[i].first].v=res[i].second;
    }
    int i;
    //有错误的节点，不被连起来
    /*
    for (i=1;i<=n/2;i++){
        if (l1!=-1)    b[l1].next=r2;
        b[r2].v=a[r2].v,b[l2].v=a[l2].v;
        b[r2].next=l2,b[l2].next=-1;
        r1=r2,l1=l2;
        r2=a[r2].pre,l2=a[l2].next;
    }
    */
    if (n%2==1)    b[res[(n+1)/2-1].first].next=res[(n+1)/2].first,b[res[(n+1)/2].first].v=res[(n+1)/2].second,b[(n+1)/2-1].next=-1;
    for ( i=t;b[i].next!=-1;i=b[i].next){
        printf("%05d %d %05d\n",i,b[i].v,b[i].next);
    }
    printf("%05d %d -1",i,b[i].v);
}