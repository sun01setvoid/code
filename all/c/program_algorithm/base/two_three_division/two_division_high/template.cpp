#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL num[N], pre2[N], pre5[N];
int n, k;
int check(LL x)
{
    LL res = 0;
    LL ans = 0;
    int l = 1;
    for (int i = 1; i <= n; i++)
    {
        if (res + num[i] + (pre5[i] - pre5[i - 1]) * (pre2[i - 1] - pre2[l - 1]) > x)
            res = num[i], ans++, l = i;
        else
            res += num[i] + (pre5[i] - pre5[i - 1]) * (pre2[i - 1] - pre2[l - 1]);
    }
    return ans + 1;
}
int main()
{
    cin >> n >> k;
    LL tmp;
    LL ma = 0, L=0;
    bool f=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        LL cnt = 0, sum = 0;
        pre2[i] = pre2[i - 1];
        pre5[i] = pre5[i - 1];
        LL x = tmp;
        LL len = 1;
        while (x)
        {
            len *= 10;
            x /= 10;
        }
        len /= 10;
        for (LL j = len; j >= 1; j /= 10)
        {
            if (tmp / j % 10 == 2)
                pre2[i]++, cnt++;
            else if (tmp / j % 10 == 5)
            {
                ma += pre2[i];
                sum += cnt;
                pre5[i]++;
            }
        }
        num[i]=sum;
        L=max(L,num[i]);
    }
    LL l = L, r = ma;
    LL ans;
    while (l <= r)
    {
        LL mid = l + r >> 1;
        if (check(mid) <= k)
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}