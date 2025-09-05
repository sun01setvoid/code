#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
//再不卷就退役了
const int mod=1e9+7;
int max(int a,int b){
    return a>b?a:b;
}
int fp(int x,int y){
    int res=1;
    while(y){
        if(y%2)res=res*x%mod;
        y/=2;
        x=x*x%mod;
    }
    return res;
}
int C(int n, int k)
{
    if(k==0)return 1ll;
    int res=1,res1=1;
    if(k*2>n)k=n-k;
    for(int i=1;i<=k;i++)res=res*(n-k+i)%mod;
    for(int i=1;i<=k;i++)res1=res1*i%mod;
    res=res*fp(res1,mod-2)%mod;
    return res;
}
void solve()
{
    int n, r;
    cin >> n >> r;
    vector<int> a(n + 1), mx(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
        mx[i] = max(mx[i + 1], a[i]);
    mx[0] = r;
    int ans = 0;
    int x = 1;
    int cnt = 1, nn = mx[n],pr=-1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (mx[i] == nn)
            cnt++;
        else
        {
            int tn = n - i;
            int tm = mx[i] - nn + 1;
            int z = C(tm + tn - 1, tm - 1) % mod;
            int y = C(tm-1+cnt, tm - 1) % mod;
            int tt=0;
            if(pr!=-1){
                int mm=nn-pr+1;
                int nn=n-i-cnt;
                tt=C(mm + nn - 1, mm - 1) % mod;
            }
            x = (z + y * x % mod - y + mod) % mod;
            x=(x+tt)%mod;
            cnt = 1;
            pr=nn;
            nn = mx[i];
        }
    }
    int tn = n;
    int tm = mx[0] - mx[1] + 1;
    int z = C(tm + tn - 1, tm - 1) % mod;
    int y = C(tm-1+cnt, tm - 1) % mod;
    int tt=0;
    if(pr!=-1){
        int mm=nn-pr+1;
        int nn=n-cnt;
        tt=C(mm + nn - 1, mm - 1) % mod;
        cout<<mm<<" "<<nn<<" "<<tt<<endl;
    }
    ans = (z + y * x % mod - y + mod) % mod;
    ans=(ans+tt)%mod;
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t=1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}