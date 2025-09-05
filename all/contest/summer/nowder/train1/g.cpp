#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
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
#define lb lower_bound
#define ub upper_bound
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
const int N = 1e5 + 10;
int nxt[N];
char str1[N], str2[N]; // 字符串从1开始
void find_next(char *s)
{
    int j = 0;
    for (int i = 2; s[i] != '\0'; i++)
    {
        if (j && s[j + 1] != s[i])
            j = nxt[j]; // 往前还能不能判断
        if (s[i] == s[j + 1])
            j++;
        nxt[i] = j;
    }
}
//-----------------------------------------------------//

void solve()
{
    int n, q, a;
    cin >> n >> q;
    scanf("%s", str1 + 1);
    while (q--)
    {
        
    }
}
signed main()
{
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}