#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N];
int n,m,k;
int check(int x){
    int ans=0;
    for (int i=1,j=m;i<=n;i++){
        while (j>=1 && a[i]+b[j]>x){
            j--;
        }
        if (j==0) break;
        ans+=j;
    }
    return ans;
}
signed main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]*a[i];
    }
    for (int i=1;i<=m;i++){
        cin>>b[i];
        b[i]=b[i]*b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int l=a[1]+b[1],r=a[n]+b[m];
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)>=k){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l;
}