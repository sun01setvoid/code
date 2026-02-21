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
        //这里一定保证了，i，j不会越界,可以思考一下所有情况
        
        // while (i<r && q[++i]<=x);
        // while (j>l && q[--j]>=x);
        //这样会mle+tle
        //！！！因为首先比一定有比x小的和大的，i，j不限制会越界
        //限制的话，i会停在r位置或j会停在l位置
        // 5
        //1 5 5 2 3
        //将j限制在了r,无法移动，所以tle+mle
        if (i<j)
            swap(q[i],q[j]);
    }
    cout<<"l="<<l<<" r="<<r<<endl;
    cout<<"i="<<i<<" j="<<j<<endl;
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