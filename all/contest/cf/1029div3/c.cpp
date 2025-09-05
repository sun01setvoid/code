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
#define Yes cout << "Yes\n"
#define No cout << "No\n"
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
    int n;
    cin>>n;
    vii a(n+1);vector <vii> pos(n+1);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,int> mp1,mp2;
    int i;
    int k=1;
    mp2[a[1]]=0;
    mp1=mp2;
    int cnt=0;
    int j;
    for (j=2;j<=n;j++){
        if (mp1.count(a[j]) && mp1[a[j]]==0) mp1[a[j]]=1,cnt++;
        if (!mp2.count(a[j])) mp2[a[j]]=0;
        if (cnt==mp1.size()){
            mp1=mp2;
            mp2.clear();
            k++;
            cnt=0;
        }
    }
    cout<<k<<endl;
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