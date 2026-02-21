// P10777
// 维护连通块欧拉回路
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
int p[maxn], d[maxn], sz[maxn], bk[maxn];
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
vector<array<int, 3>> ed;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ed.pb({a, b, c});
        int fa = find(a), fb = find(b);
        if (fa != fb)
        {
            p[fa] = fb;
            bk[fb] += bk[fa] + (c == 1);
        }
        else
            bk[fb] += (c == 1);
        if (c == 1)
            d[a] ^= 1, d[b] ^= 1;
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        p[i] = find(i);
        s.insert(p[i]);
        if (d[i] & 1)
            sz[p[i]]++;
    }
    int cnt = s.size(), res = 0, oth = 0;
    for (auto x : s)
    {
        if (sz[x] == 0 && bk[x])
            res++;
        else if (sz[x] == 0 && !bk[x])
            oth++;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        // cout << res << " " << oth << endl;
        int op;
        cin >> op;
        if (op == 2)
        {
            if (res + oth != cnt)
                cout << -1 << endl;
            else
                cout << res << endl;
        }
        else
        {
            int x;
            cin >> x;
            auto &[u, v, c] = ed[x];
            d[u] ^= 1, d[v] ^= 1;
            // cout << u << " " << v << " " << d[u] << " " << d[v] << endl;
            int st = sz[p[u]], pbk = bk[p[u]];
            if (c == 0)
                bk[p[u]]++, c = 1;
            else
                bk[p[u]]--, c = 0;
            if (d[u] == 1)
                sz[p[u]]++;
            else
                sz[p[u]]--;
            if (d[v] == 1)
                sz[p[v]]++;
            else
                sz[p[v]]--;
            if (st == 0)
            {
                if (pbk == 0)
                {
                    if (bk[p[u]] != 0)
                    {
                        oth--;
                        if (sz[p[u]] == 0)
                            res++;
                    }
                }
                else
                {
                    if (sz[p[u]] > 0)
                        res--;
                }
            }
            else
            {
                if (bk[p[u]] == 0)
                    oth++;
                else
                {
                    if (sz[p[u]] == 0)
                        res++;
                }
            }
        }
    }
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