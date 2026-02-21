#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int a[maxn];
//阶梯nim,无限长的算0阶梯
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=0,n=n+1;
    sort(a+1,a+n+1);
    for (int i=n;i>=2;i-=2){
        ans^=(a[i]-a[i-1]-1);
    }
    if (ans)cout<<"Georgia will win"<<endl;
    else cout<<"Bob will win"<<endl;
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