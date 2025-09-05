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
const int maxm = 6e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int x, y, s;
};
int n, m;
const int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void Raze()
{
    cin >> n >> m; queue<oo>q; int mx = 0; bool f = 0;
    vector<vii>mp(n + 1, vii(m + 1, 0));
    vector<vii>val(n + 1, vii(m + 1, 0));
    vector<vii>vis(n + 1, vii(m + 1, 0));
    vector<vector<pii>>pos(n + m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])f = 1;
        }
    }
    if (!f)
    {
        cout << n + m - (n + 1) / 2 - (m + 1) / 2 << endl; return;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                vis[i][j] = 1; pos[0].pb({ i,j }); q.push({ i,j,0 });
            }
        }
    }
    while (q.size())
    {
        auto it = q.front(); q.pop();
        int x = it.x, y = it.y, s = it.s;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0], yy = y + dir[i][1], ss = s + 1;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy])
            {
                q.push({ xx,yy,ss }); vis[xx][yy] = 1; 
                val[xx][yy] = ss; pos[ss].pb({xx,yy}); mx = max(mx, ss);
            }
        }
    }
    int l = 0, r = (n + m + 1);
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        //int mi = INF, ma = 0;
        vector<pii>tmp;
        int maxadd = -INF, minadd = INF;
        int maxjian = -INF, minjian = INF;
        for (int i = mid + 1; i <= mx; i++)
        {
            for (auto it : pos[i])
            {
                tmp.pb(it);
            }
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            maxadd = max(maxadd, tmp[i].fi + tmp[i].so);
            minadd = min(minadd, tmp[i].fi + tmp[i].so);
            maxjian = max(maxjian, tmp[i].fi - tmp[i].so);
            minjian = min(minjian, tmp[i].fi - tmp[i].so);
        }
        int ans = INF;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int add = i + j;
                int jian = i - j;
                int a1 = add - minadd;
                int a2 = maxadd - add;
                int a3 = jian - minjian;
                int a4 = maxjian - jian;
                int maxx = max(max(a1, a2), max(a3, a4));
                ans = min(ans, maxx);
            }
        }
        if (ans <= mid)r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    //cin >> _;
    while (_--)Raze(); return 0;
}