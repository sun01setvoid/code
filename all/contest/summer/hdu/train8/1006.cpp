#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
//#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 2e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
};
ll n, Q;
ll a[maxn];
ll t[maxn << 2][4][4];
ll max(ll a, ll b) { return a >= b ? a : b; }
ll min(ll a, ll b) { return a <= b ? a : b; }
void up(int node, int l, int r)
{
    int mid = (l + r) >> 1;
    int len1 = (mid - l + 1), len2 = (r - mid);
    if (len1 > 6 && len2 > 6)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (t[node << 1][i][j] == -INF)
                    continue;
                // if (i + j >= len1 && (i != j || i != len1 || j != len1))continue;
                for (int k = 3 - j; k >= 0; k--)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (t[node << 1 | 1][k][l] == -INF)
                            continue;
                        // if (k + l >= len1 && (k != l || k != len2 || l != len2))continue;
                        t[node][i][l] = max(t[node][i][l], t[node << 1][i][j] + t[node << 1 | 1][k][l]);
                    }
                }
            }
        }
    }
    else
    {
        int ml = min(len1 + 1, 4), mr = min(len2 + 1, 4);
        for (int i = 0; i < ml; i++)
        {
            for (int j = 0; j < ml; j++)
            {
                if (t[node << 1][i][j] == -INF)
                    continue;
                if (i + j >= len1 && i != j)
                {
                    continue;
                }
                if (i + j >= len1)
                {
                    if (i != len1 || j != len1)
                        continue;
                }
                for (int k = 3 - j; k >= 0; k--)
                {
                    for (int l = 0; l < mr; l++)
                    {
                        if (t[node << 1 | 1][k][l] == -INF)
                            continue;
                        if (k + l >= len1 && k != l)
                            continue;
                        if (k + l >= len2)
                        {
                            if (k != len2 || l != len2)
                                continue;
                        }
                        if (len1 <= i + j && len2 <= l + k)
                        {
                            t[node][len1 + k][len2 + j] = max(t[node][len1 + k][len2 + j], t[node << 1][i][j] + t[node << 1 | 1][k][l]);
                        }
                        else if (len1 <= i + j)
                        {
                            t[node][len1 + k][l] = max(t[node][len1 + k][l], t[node << 1][i][j] + t[node << 1 | 1][k][l]);
                        }
                        else if (len2 <= l + k)
                        {
                            t[node][i][len2 + j] = max(t[node][i][len2 + j], t[node << 1][i][j] + t[node << 1 | 1][k][l]);
                        }
                        else
                        {
                            t[node][i][l] = max(t[node][i][l], t[node << 1][i][j] + t[node << 1 | 1][k][l]);
                        }
                    }
                }
            }
        }
    }
}
void build(int node, int l, int r)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            t[node][i][j] = -INF;
    if (l == r)
    {
        t[node][0][0] = 0;
        t[node][1][1] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    up(node, l, r);
}
void upd(int node, int l, int r, int p, int v)
{
    if (l == r)
    {
        t[node][1][1] = v;
        return;
    }
    int mid = (l + r) >> 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            t[node][i][j] = -INF;
    if (p <= mid)
        upd(node << 1, l, mid, p, v);
    else
        upd(node << 1 | 1, mid + 1, r, p, v);
    up(node, l, r);
}
ll q()
{
    ll ma = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 3 - i; j >= 0; j--)
            if (i + j <= 3)
                ma = max(ma, t[1][i][j]);
    return ma;
}
void Raze()
{
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cout << q() << endl;
    while (Q--)
    {
        int x, v;
        cin >> x >> v;
        upd(1, 1, n, x, v);
        a[x] = v;
        cout << q() << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}