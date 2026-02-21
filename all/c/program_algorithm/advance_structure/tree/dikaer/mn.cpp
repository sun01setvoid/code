#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define fi first
#define se second
#define endl '\n'
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << endl
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
const int mod = 1e9+7;
int d1[maxn],d2[maxn],d3[maxn],d4[maxn];
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) d1[i]=d2[i]=d3[i]=d4[i]=0;
    for (int i=1;i<=m;i++){
        int id,ps;
        cin>>id>>ps;
        if (id==1){
            d1[ps]++;
        }else if (id==2) d2[ps]++;
        else {
            d3[ps]+=2;
            d4[ps]--;
        }
    }
    for (int i=1;i<=n;i++) d1[i]=(d1[i-1]+d1[i])%mod;
    for (int i=1;i<=n;i++) d2[i]=(d2[i-1]+d2[i])%mod;
    for (int i=1;i<=n;i++) d2[i]=(d2[i-1]+d2[i])%mod;
    for (int i=1;i<=n;i++) d3[i]=(d3[i-1]+d3[i])%mod;
    for (int i=1;i<=n;i++) d3[i]=(d3[i-1]+d3[i]+d4[i])%mod;
    for (int i=1;i<=n;i++) d3[i]=(d3[i-1]+d3[i])%mod;
    for (int i=1;i<=n;i++){
        cout<<((d1[i]+d2[i]+d3[i])%mod+mod)%mod<<" ";
    }
    cout<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}