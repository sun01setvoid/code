#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100010;

LL a[N];

int main()
{
    int T=1,n,q;
    scanf("%d", &T);
    for (int C = 1; C <= T; C ++ )
    {
        printf("Case #%d:\n", C);
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) scanf("%lld", &a[i]);
        int k = 0;
        for (int i = 62; i >= 0; i -- )
        {
            for (int j = k; j < n; j ++ )
                if (a[j] >> i & 1)
                {
                    swap(a[j], a[k]);
                    break;
                }
            if (!(a[k] >> i & 1)) continue;
            for (int j = 0; j < n; j ++ )
                if (j != k && (a[j] >> i & 1))
                    a[j] ^= a[k];
            k ++ ;
            if (k == n) break;
        }
        reverse(a, a + k); //因为求的是k小异或和
        scanf("%d", &q);
        while (q -- )
        {
            LL x;
            scanf("%lld", &x);
            if (k < n) x -- ;//看是否有异或和为0
            if (x >= (1ll << k)) puts("-1");
            else
            {
                LL res = 0;
                for (int i = 0; i < k; i ++ )
                    if (x >> i & 1)
                        res ^= a[i];
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}