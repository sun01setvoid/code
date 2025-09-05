#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b)
{
    int ans = 0;
    while (!(a == 1 && b == 1))
    {
        if (a > b)
            a = (a + 1) / 2;
        else
            b = (b + 1) / 2;
        ans++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int ans;
        ans = solve(n, min(b, m - b + 1));
        ans = min(ans,solve(min(a , n - a+1), m));
        cout << ans + 1 << "\n";
    }
}