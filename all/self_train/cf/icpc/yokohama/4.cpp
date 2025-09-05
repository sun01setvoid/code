#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int li[maxn], ri[maxn];
int dfs1(string &s, int pos, int val, int f)
{
    
}
int dfs2(string &s, int pos, int val, int f)
{

}
void solve()
{
    string a, b;
    cin >> a >> b;
    memset(li, 0x3f, sizeof li);
    memset(ri, 0x3f, sizeof ri);
    dfs1(a, 0, 0, 0);
    dfs2(a, a.size() - 1, 0, 1);
    dfs1(b, 0, 0, 0);
    dfs2(b, b.size() - 1, 0, 1);
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}