#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
};
int n, k;
string s;
bool check(int x)
{
    return s.substr(x, 7) == "nanjing";
}
void Raze()
{
    cin >> n >> k >> s;
    for (int i = 0; i < min(k, n); i++)
    {
        s += s[i];
    }
    int idx = -1;
    for (int i = 0; i + 6 <= s.size() - 1; i++)
    {
        if (check(i))
        {
            idx = i;
            break;
        }
    }
    int l = idx, r = min((int)s.size() - 1, l + n - 1);
    int ans = 0;
    for (int i = l; i + 6 <= r; i++)
    {
        if (check(i))
            ans++;
    }
    cout << ans << endl;
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
