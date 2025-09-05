#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a,st,en)             \
    cerr << #a << "=[";             \
    repn(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
void solve()
{
    vector <vii> dp(26);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=n-1;
    for (int i=0;i<n-1;i++){
        if (s[i]>s[i+1]){
            ans=i;break;
        }
    }
    if (ans==n-1) cout<<s<<endl;
    else {
        int i;
        for (i=ans+1;i<=n-1;i++){
            if (s[i]>s[ans]) break;
        }
        if (i==n) s+=s[ans];
        else s.insert(i,1,s[ans]);
        s.erase(ans,1);
        cout<<s<<endl;
    }
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