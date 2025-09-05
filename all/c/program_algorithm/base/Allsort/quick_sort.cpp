#include <iostream>
#include <cstdio>
using namespace std;
int n;
const int N=100010;
int q[N];
void qs(int q[],int l,int r){
    if (l>=r)   return;
    int x=q[l+r>>1],i=l-1,j=r+1;//一般选中间，防止一开始直接有序的情况
    while (i<j){
        while (q[++i]<x);
        while (q[--j]>x);
        if (i<j)
            swap(q[i],q[j]);
    }
    qs(q,l,j);qs(q,j+1,r);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
       scanf("%d",&q[i]);
    }
    qs(q,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d ",q[i]);
}