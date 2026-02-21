#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << endl
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 5e6;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
void solve()
{
    int w,h,d;
    cin>>w>>h>>d;
    int n;
    cin>>n;
    if ((__int128)w*h*d%n) cout<<-1<<endl;
    else {
        int dd=__gcd(w,n);
        cout<<dd-1<<" ";
        n/=dd;
        dd=__gcd(h,n);
        cout<<dd-1<<" ";
        n/=dd;
        dd=__gcd(d,n);
        cout<<dd-1<<" ";
        n/=dd;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}