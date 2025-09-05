// lg  P10975    mondriaan's dream
// 只排横的，剩下的竖着的只有1种方法插入
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 12, M = 1 << 12;
vector<ll> vc[M];
bool st[M];
ll f[N][M];
int main()
{
    ll n, m;
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i++)
        {
            int cnt = 0;
            bool flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        flag = 0;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                flag = 0;
            st[i] = flag;
        }
        for (int i = 0; i < 1 << n; i++)
        {
            vc[i].clear(); // 重置
            for (int j = 0; j < 1 << n; j++)
            {
                if ((i & j) == 0 && st[i | j])
                    vc[i].push_back(j);
            }
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1; // 第1行有方案数1
        for (int i = 1; i <= m; i++)
        { // 从i==1,即第二行开始
            for (int j = 0; j < 1 << n; j++)
            {
                for (auto k : vc[j])
                {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        // 从0->m-1行
        cout << f[m][0] << endl;
    }
}
/*
//轮廓线dp(逐格dp)
nm*2^m O(1)转移
还有轮廓线写法，m个状态的二进制数不断轮换，如果k5==1,要~<<(m-1))，，不断<<1,转变轮廓线，注意是否是第一行或第一列，行突与列突
dp[i][j][k]->dp[2][k]
每次滚动时memset(dp),因为是加法
//状压dp
n*2^m*O(转移)
O(转移一般是2^m)
*/