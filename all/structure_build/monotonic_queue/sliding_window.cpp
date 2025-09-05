//lg p1886
//维护一个单调的双端队列，去除冗余,不需要的元素，O(N)
#include <iostream>
using namespace std;
const int N=1e6+10;
int q[N],a[N];//q存下标，这样才能保证窗口长度
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)   cin>>a[i];
    int hh=0,tt=-1;
    for (int i=0;i<n;i++){
        //if or while(condition)可能长度不固定，但要保证头尾指针单调
        while (hh<=tt && i-k+1>q[hh]) hh++;
        while (hh<=tt && a[q[tt]]>=a[i]) tt--;
        q[++tt]=i;
        if (i>=k-1) cout<<a[q[hh]]<<" ";
    }
    cout<<endl;
    hh=0,tt=-1;
    for (int i=0;i<n;i++){
        //if or while(condition)可能长度不固定，但要保证头尾指针单调
        while (hh<=tt && i-k+1>q[hh]) hh++;
        while (hh<=tt && a[q[tt]]<=a[i]) tt--;
        q[++tt]=i;
        if (i>=k-1) cout<<a[q[hh]]<<" ";
    }
}