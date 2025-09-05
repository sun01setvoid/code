#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt1=0,cnt2=0;
    int ans=0;
    bool f=0;
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1]) ++cnt2,f=1;
        else if (a[i]<a[i-1] && f) f=0,ans+=cnt1*cnt2,cnt1=cnt2,cnt2=0;
    }
    ans+=cnt1*cnt2;
    cout<<ans;
}