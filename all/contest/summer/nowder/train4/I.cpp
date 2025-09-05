/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>
#include <map>
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
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
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
using namespace std;
int mp[55][55];
pii pre[55][55];
int dist[55][55];
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 };
vector <pii> path;
vector<pair<pii, pii>> ans;
int px, py;
int n, m;
//-----------------------------------------------------//
void bfs(int x, int y) {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            dist[i][j] = inf;
        }
    }
    queue<pii> q;
    q.push(pii(x, y));
    dist[x][y] = 0;
    px = py = -1;
    path.clear();
    while (q.size()) {
        int stx = q.front().first, sty = q.front().second;
        //debug(stx);debug(sty);
        q.pop();
        if (mp[stx][sty] == '*') {
            ;
            px = stx, py = sty;
            while (dist[stx][sty] != 0) {
                path.pb(pii(stx, sty));
                tie(stx, sty) = pre[stx][sty];
            }
            path.pb(pii(stx, sty));
            return;
        }
        for (int i = 0;i < 4;i++) {
            int nx = dir[i][0] + stx, ny = dir[i][1] + sty;
            if (nx<1 || nx>n || ny<1 || ny>m) continue;
            if (mp[nx][ny] != '#' && dist[nx][ny] > dist[stx][sty] + 1) {
                q.push({ nx,ny });
                dist[nx][ny] = dist[stx][sty] + 1;
                pre[nx][ny] = pii(stx, sty);
            }
        }

    }
}
void col() {
    int now = 0;
    for (int i = 1;i < (int)path.size();i++) {
        if (mp[path[i].fi][path[i].se] != '.') {
            for (int j = i;j > now;j--) {
                ans.push_back(make_pair(path[j], path[j - 1])); //处理过程中有箱子
            }
            now = i;
        }
    }
    mp[path.back().fi][path.back().se] = '.'; mp[path[0].fi][path[0].se] = '!';
}
char getdir(pair<pii, pii> p) {
    if (p.se.fi == p.fi.fi + 1) return 'D';
    if (p.se.fi == p.fi.fi - 1) return 'U';
    if (p.se.se == p.fi.se + 1) return 'R';
    if (p.se.se == p.fi.se - 1) return 'L';
    return 0;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < (int)s.size();j++) {
            mp[i][j + 1] = s[j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (mp[i][j] == '@') {
                bfs(i, j);
                //debug(px);
                if (px == -1) {
                    cout << "-1" << endl;
                    return;
                }
                col();
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.fi.first << " " << i.fi.second << " " << getdir(i) << endl;
    }
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
*/