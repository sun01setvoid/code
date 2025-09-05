#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ls p << 1
#define rs p << 1 | 1
#define fi first
#define se second
#define pa pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ull unsigned long long
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
// 再不卷就退役了
const int z = 1e6 + 10;
const int zz = 1e6;
const int B = 2000;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
unordered_map<ull, int> mp;
std::mt19937 eng(std::chrono::steady_clock::now().time_since_epoch().count());
ull rnd(ull l = 0ull, ull r = ~0ull) { return std::uniform_int_distribution<ull>(l, r)(eng); }
int a[10][10], b[10][10];
int id, m, k, n;
ull get1()
{
    ull num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            num = num * 131 + a[i][j];
    return num;
}
ull get2()
{
    ull num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            num = num * 13331 + a[i][j];
    return num;
}
void op()
{
    int x = rnd() % (n - 3), y = rnd() % (n - 3);
    int aa[4][4];
    //debug(x);
    //debug(y);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            aa[j][3 - i] = a[x + i][y + j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[x + i][y + j] = aa[i][j];
}
void init()
{
    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = num++;
    mp[get1()] = 1;
    mp[get2()] = 1;
    int ma=5e5;
    for (int p = 1; p <= ma-1; p++)
    {
        op();
        ull tt1=get1(),tt2=get2();
        mp[tt1]=max(mp[tt1],ma-p);
        mp[tt2]=max(mp[tt2],ma-p);
    }
}
void solve()
{
    cin >> id >> m >> k >> n;
    init();
    int t;
    vector<pa> ans(100);
    vii res(100, 0);
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < k; j++)
        {
            ull num1 = 0;
            ull num2 = 0;
            for (int ii = 0; ii < n; ii++)
            {
                for (int jj = 0; jj < n; jj++)
                {
                    cin >> t;
                    num1 = num1 * 131 + t;
                    num2 = num2 * 13331 + t;
                }
            }
            if (mp.count(num1) && mp.count(num2))
                cnt+=mp[num1];
        }
        ans[i] = {cnt, i};
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < m / 2; i++)
        res[ans[i].se] = 1;
    for (int i = 0; i < m; i++)
        cout << res[i];
    cout << endl;
}
signed main()
{
    IOS;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
