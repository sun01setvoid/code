// P3195 [HNOI] 玩具装箱
// 以i为常数
// 给把j转换给(k,b),i做x
// 斜率优化dp
// 以i为未知数的划分是否有？
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
struct Line
{
    int m, c; // y = m*x + c
    Line(int _m = 0, int _c = inf / 2) : m(_m), c(_c) {}
    int get(int x) const { return m * x + c; }
};
struct LiChao
{
    const int infLL = (1LL << 62);
    struct Node
    {
        Line ln;
        Node *l, *r;
        Node(const Line &_ln) : ln(_ln), l(nullptr), r(nullptr) {}
    };
    Node *root;
    int L, R; // 不超过1e12就行
    LiChao(int _L = 0, int _R = 0) : root(nullptr), L(_L), R(_R) {}
    void insert(Line nw) { insert(root, L, R, nw); }
    void insert(Node *&node, int l, int r, Line nw)
    {
        if (!node)
        {
            node = new Node(nw);
            return;
        }
        int mid = l + (r - l) / 2;
        bool lef = nw.get(l) < node->ln.get(l);
        bool midb = nw.get(mid) < node->ln.get(mid);
        if (midb)
            swap(nw, node->ln);
        if (l == r)
            return;
        if (lef != midb)
            insert(node->l, l, mid, nw);
        else
            insert(node->r, mid + 1, r, nw);
    }
    int query(int x) { return query(root, L, R, x); }
    int query(Node *node, int l, int r, int x)
    {
        if (!node)
            return infLL;
        int res = node->ln.get(x);
        if (l == r)
            return res;
        int mid = l + (r - l) / 2;
        if (x <= mid)
            return min(res, query(node->l, l, mid, x));
        else
            return min(res, query(node->r, mid + 1, r, x));
    }
};
int pre[maxn];
int dp[maxn];
void solve()
{
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> pre[i], pre[i] += pre[i - 1], dp[i] = inf;
    l = l;
    LiChao lic(-l - 10, pre[n] + n + 10);
    dp[0] = 0;
    lic.insert(Line(0, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min(dp[i], lic.query(pre[i] + i - l - 1) + (pre[i] + i - l - 1) * (pre[i] + i - l - 1));
        lic.insert(Line(-2 * (pre[i] + i), dp[i] + (pre[i] + i) * (pre[i] + i)));
    }
    cout << dp[n] << endl;
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