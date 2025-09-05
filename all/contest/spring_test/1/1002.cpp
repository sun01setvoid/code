#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int MOD = 998244353;
int inv2;
int fpow(int a, int k, int p)
{
    int ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % p;
        a = a * a % p;
        k = k / 2;
    }
    return ans;
}
void solve()
{
    int ans = 1;
    int n, k;
    cin >> n >> k;
    vector<int> p(k), f(k, 1);
    int win;
    cin >> win;
    --win;
    for (int &i : p)
        cin >> i, --i;
    sort(p.begin(),p.end());
    while (!p.empty())
    {
        vector<int> q, g;
        win = win >> 1;
        for (int i = 0; i < p.size();)
        {
            if (p[i] >> 1 == win)
            {
                ans = ans * (MOD + 1 - f[i]) % MOD;
                ++i;
            }
            else
            {
                q.push_back(p[i] >> 1);
                if (i + 1 < p.size() && (p[i]>>1) == (p[i + 1]>>1))
                {
                    g.push_back((f[i] + f[i + 1]) % MOD * inv2 % MOD);
                    ++i, ++i;
                }
                else if ((p[i] ^ 1) < n)
                {
                    g.push_back(f[i] * inv2 % MOD);
                    ++i;
                }
                else
                {
                    g.push_back(f[i]);
                    ++i;
                }
            }
        }
        p = q, f = g;
        n = (n + 1) >> 1;
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    inv2 = fpow(2, MOD - 2, MOD);
    while (t--)
    {
        solve();
    }
}
// 前偶后奇,>>1找父亲