#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 5e5 + 10, M = 6e6 + 10;
int primes[N], cnt;
bool st[M];
int a[N];
int sum[N], psum[N];
bool cmp(int a, int b)
{
    return a > b;
}
void isp(int n)
{
    cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 1; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    isp(6000000);
    psum[0] = 0;
    sum[0] = 0;
    for (int i = 1; i < cnt; i++)
        psum[i] = psum[i - 1] + primes[i];
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        bool f = 0;
        int i;
        for (i = n; i >= 2; i--)
        {
            if (psum[i] <= sum[i])
            {
                f = 1;
                // cout<<n-i<<"\n";
                break;
            }
        }
        if (f)
            cout << n - i << "\n";
        else
            cout << n-1 << "\n";
    }
}