#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL check2(LL x) 
{
    if (x == 0) return 6;
    int pc = __builtin_popcountll(x);
    if (pc >= 3) return x;
    return x + 2;
}
LL check1(LL x) 
{
    if (x == 0) return 2;
    if (x == 1) return 5;
    if (__builtin_popcountll(x) >= 2) return x;
    return x + 2;
}
int main()
{
    int t; 
    cin >> t;
    while(t--)
    {
        LL n, x;
        cin >> n >> x;
        if(x == 0)
        {
            if(n == 1) cout << -1 << "\n";
            else if((n & 1) == 0)   cout << n << "\n";
            else    cout << n + 3 << "\n";
            continue;
        }
 
        LL ans = 0x3f3f3f3f3f3f3f3f;
 
        for(int i = 1; i <= 3; i++)
        {
            if(i > n) break;
            LL a1 = n - i,r = a1 & 1,y = x ^ r,res;
            if(i == 1)
            {
                if(y >= 1) res = y;
                else continue;
            }
            else if(i == 2) res = check1(y);
            else    res = check2(y);
            ans = min(ans, n - i + res);
        }
 
        for(int i = 0; i < 2; i++)
        {
            if(n - i < 1) continue;
            LL y = x ^ i;
            if(y == 0) continue;
            int p = __builtin_popcountll(y);
            int ma = (int)((n - i) & 1);
            int ma1 = (p & 1) == ma ? p : p - 1;
            if(ma1 >= 1 && ma1 <= n)    ans = min(ans, (n - ma1) + y);
        }
 
        cout << ans << "\n";
    }
    return 0;
}