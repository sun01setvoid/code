//P6078 Sweets
#include <iostream>
using namespace std;
#define int long long
const int mod = 2004;
int n, a, b;
int m[11];
int fac = 1;
int ans;

int C(int n_, int m)
{
    int MOD = fac * mod;
    int ret = 1;
    for (int i = n_ - m + 1; i <= n_; i++)
        ret = (ret * i) % MOD;
    return (ret / fac) % mod;
}

void dfs(int step, int type, int k, int all)
{
    if (k > all)
        return;
    if (step == n + 1)
    {
        ans = (ans + type * C(n + all - k, n) + mod) % mod;
        return;
    }
    dfs(step + 1, type, k, all);
    dfs(step + 1, -type, k + m[step] + 1, all);
}
int search(int len)
{
    ans = 0;
    dfs(1, 1, 0, len);
    return ans;
}
signed main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        fac *= i;
    }

    int lenb = search(b);
    int lena = search(a - 1);
    // 上下界条件不一样，建议分开写，讲就是a这时候没值（是0）,但是b有
    cout << (lenb - lena + mod) % mod << endl;

    return 0;
}