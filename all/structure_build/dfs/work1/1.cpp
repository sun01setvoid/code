#include <iostream>
using namespace std;
const int N=1e4+10;
int a[N];
int cnt=0;
int dfs1(int l,int r){
    if (l==r)    return a[l];
    int mid=l+r>>1;
    int ma1=dfs1(1,mid);
    int ma2=dfs1(mid+1,r);
    return max(ma1,ma2);
}
int dfs2(int l,int r){
    if (l==r)    return a[l];
    int mid=l+r>>1;
    int mi1=dfs2(1,mid);
    int mi2=dfs2(mid+1,r);
    return min(mi1,mi2);
}
int main(){
    int n;
    while (cin>>n){
        ++cnt;
        a[cnt]=n;
    }
    cout<<dfs2(1,cnt)<<","<<dfs1(1,cnt);
}