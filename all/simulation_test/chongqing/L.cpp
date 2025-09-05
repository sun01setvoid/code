
#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
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
const int maxn = 2e5 + 10;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};
int n;
void Raze()
{
    cin >> n; int sum = 0; int tot = 0;
    deque<int>dq;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        if (s == "Push")
        {
            int x; cin >> x;
            sum = (sum + x) % mod;
            if (dq.size() == n)
            {
                dq.pb(x); dq.pop_front();
            }
            else
            {
                dq.pb(x);
            }
        }
        else if (s == "Pop")
        {
            int x = dq.back();
            sum = (sum - x + mod) % mod;
            dq.pop_back();
        }
        else
        {
            sum = (sum * 2) % mod;
            if (dq.size() * 2 <= n)
            {
                vii tmp;
                while (dq.size())tmp.pb(dq.front()), dq.pop_front();
                for (int i = 0; i < tmp.size(); i++)dq.pb(tmp[i]);
                for (int i = 0; i < tmp.size(); i++)dq.pb(tmp[i]);
            }
            else if (dq.size() == n)continue;
            else
            {
                vii tmp; int len = dq.size(); len = n - len;
                while (dq.size())tmp.pb(dq.front()), dq.pop_front();
                for (int j = tmp.size() - len; j < tmp.size(); j++)dq.pb(tmp[j]);
                for (int j = 0; j < tmp.size(); j++)dq.pb(tmp[j]);
            }
        }
        cout << sum << endl;
    }
    
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    //cin >> _;
    while (_--)Raze(); return 0;
}
/*
Push 1
Push 2
Push 3
Push 4
Push 5
Push 6
Push 7
Repeat

*/