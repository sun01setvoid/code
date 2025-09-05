#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 2e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};
int n, m, a[maxn], b[maxn]; string s, t;
void Raze()
{
    cin >> n >> m >> s >> t; int len = t.size();
    s = " " + s; t = " " + t; int ans = 0;
    for (int i = 1; i <= n; i++)a[i] = s[i] - '0';
    for (int i = 1; i <= m; i++)b[i] = t[i] - '0';
    int id = -1;
    for (int j = 1; j <= m; j++)
    {
        if (b[j] == 1) { id = j; break; }
    }
    for (int i = 1; i + len-1 <= n; i++)
    {
        if (a[i])
        {
            ans++;
            if (i < id) { cout << "-1" << endl; return; }
            for (int j = i - id + 1; j <= i - id + len; j++)
            {
                a[j] ^= b[j - i + id];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i]) { cout << "-1" << endl; return; }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}