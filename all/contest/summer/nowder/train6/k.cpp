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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 6e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    
};
int n, a[maxn];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool check(int x) 
{
    int now = 0; int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % x) {
            if (a[i - 1] % x == 0)cnt++;
            if (now == 0)now = a[i] % x;
            else if (a[i] % x != now)return false;
        }
    }
    return cnt <= 1;
}
void Raze()
{
    cin >> n; bool f = 1; set<int>st; int ma = 0;
    for (int i = 1; i <= n; i++)cin >> a[i], ma = max(ma, a[i]); int ans = 1;
    for (int i = 2; i <= n; i++)if (a[i] != a[1])f = 0;
    if (f)
    {
        cout << "0" << endl; return;
    }
    for (int j = 2; j <= sqrt(a[1]); j++)
    {
        if (a[1] % j == 0)st.insert(j), st.insert(a[1] / j);
    }
    st.insert(1); st.insert(a[1]);
    for (int j = 2; j <= sqrt(a[n]); j++)
    {
        if (a[n] % j == 0)st.insert(j), st.insert(a[n] / j);
    }
    st.insert(a[n]); int g = 0; st.insert(ma);
    for (int i = 1; i < n; i++)g = gcd(g, abs(a[i] - a[i + 1]));
    for (int v : st)
    {
        if (check(v))ans = v;
    }
    ans = max(ans, g);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}