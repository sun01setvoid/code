#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
//#define int long long
#define ull unsigned int 
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 6e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    
};
int n, k, fa[maxn]; vii mp[maxn];
void Raze()
{
    cin >> n >> k; vii tmp;
    vii vis(n + 1, 0); vis[1] = 1; vis[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i]; mp[fa[i]].pb(i);
    }
    for (int i = 1; i <= k; i++)
    {
        int u, l, r; cin >> u >> l >> r;
        if (u == 1) { cout << l << endl; return; }
        tmp.pb(u); int tu = u;
        int len = r - l + 1;
        while (1)
        {
            tu = fa[tu]; if (vis[tu])break;
            tmp.pb(tu);
        }
        if (tmp.size() <= len)
        {
            cout << tmp.size() + l - 1 << endl; return;
        }
        for (int i = tmp.size() - 1; i >= tmp.size() - len; i--)
        {
            vis[tmp[i]] = 1;
        }
        tmp.clear();
    }
    cout << "-1" << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    //cin >> _;
    while (_--)Raze(); return 0;
}
