#include <bits/stdc++.h>
using namespace std;
#define int long long 
int MOD= 998244353;
int dp1[100010],dp2[100010];
int a[100010],b[100010];
int p[100010];
signed main(){
    int t;
    cin>>t;
    p[0]=1;
    for (int i=1;i<=100000;i++) p[i]=p[i-1]*2%MOD;
    while (t--){
        int n;
        cin>>n;
        dp1[0]=0,dp2[0]=0;
        cin>>a[0];
        for (int i=1;i<n;i++) {
            cin>>a[i];
            dp1[i]=dp1[i-1];
            if (a[i]>a[dp1[i-1]]){
                dp1[i]=i;
            }
        }
        cin>>b[0];
        for (int i=1;i<n;i++) {
            cin>>b[i];
            dp2[i]=dp2[i-1];
            if (b[i]>b[dp2[i-1]]){
                dp2[i]=i;
            }
        }
        for (int i=0;i<n;i++){
            if (a[dp1[i]]>b[dp2[i]]){
                cout<<(p[a[dp1[i]]]+p[b[i-dp1[i]]])%MOD<<" ";
            }
            else if(a[dp1[i]]<b[dp2[i]]){
                cout<<(p[a[i-dp2[i]]]+p[b[dp2[i]]])%MOD<<" ";
            }else{
                if(b[i-dp1[i]]>a[i-dp2[i]]){
                    cout<<(p[a[dp1[i]]]+p[b[i-dp1[i]]])%MOD<<" ";
                }else cout<<(p[a[i-dp2[i]]]+p[b[dp2[i]]])%MOD<<" ";
            }
        }
        cout<<endl;
    }
}