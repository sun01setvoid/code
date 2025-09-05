//求逆序对数
#include <iostream>
using namespace std;
int tmp[100010],q[100010];
long long cnt=0;//long long
void mrs(int l,int r){
    if (l==r)   return;
    int m=(l+r)>>1;
    mrs(l,m);mrs(m+1,r);
    int k=0,i=l,j=m+1;
    while (i<=m && j<=r){
        if (q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++],cnt+=m-i+1;
    }
    while (i<=m)    tmp[k++]=q[i++];
    while (j<=r)    tmp[k++]=q[j++];
    for (i=l,j=0;i<=r;i++,j++)  q[i]=tmp[j];
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&q[i]);
    mrs(0,n-1);
    cout<<cnt;
}