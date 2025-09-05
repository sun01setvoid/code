#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
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
struct no
{
    int l, r, c;
    bool operator<(const no &t) const
    {
        if (l == t.l)
        {
            if (r == t.r)
                return c < t.c;
            return r < t.r;
        }
        return l < t.l;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<no> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].l >> a[i].r >> a[i].c;
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int now = 0;
    while (a[now].l == 1)
    {
        q.push({a[now].r, a[now].c});
        now++;
    }
    int ans = 0;
    for (; now < m; now++)
    {
        int l = a[now].l, r = a[now].r, mc = a[now].c;
        int cnt = 0, f = 0;
        while (q.size())
        {
            auto t = q.top();
            q.pop();
            int rr = t.first, cc = t.second;
            if (rr >= r)
            {
                q.push({rr, cc});
                break;
            }
            if (rr < l)
            {
            }
            else
            {
                if (cnt + cc > mc)
                {
                    cc -= mc - cnt;
                    cnt = mc;
                    q.push({rr, cnt});
                    q.push({r, cnt});
                    f = 1;
                    break;
                }
                else
                    cnt += cc;
            }
        }
        if (f == 0 && cnt > 0)
            q.push({r, cnt});
    }
    while (q.size())
    {
        auto cur = q.top();
        q.pop();
        if (cur.first >= n)
            ans += cur.second;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}