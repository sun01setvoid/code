//O(n**3)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;

int n;
int a[N][N];
//从0开始
int gauss()  
{
    int c, r;
    for (c = 1, r = 1; c <= n; c ++ )
    {
        int t = r;
        for (int i = r; i <= n; i ++ ) { // 找绝对值最大的行,一是防止溢出，而是刚好找是否有非零行
            if (a[i][c])
                t = i;
                break;
            }
        if (!a[t][c] ) continue;//如果是零，这一列不算，但是这行还要算

        for (int i = c; i <= n + 1; i ++ ) swap(a[t][i], a[r][i]);  // 将绝对值最大的行换到最顶端
        for (int i = r + 1; i <= n; i ++ )  // 用当前行将下面所有的列消成0
            if (a[i][c])
                for (int j = n + 1; j >= c; j -- )
                    a[i][j] ^= a[r][j];
        r ++ ;
    }

    if (r < n + 1)
    {
        for (int i = r; i <= n; i ++ )
            if (a[i][n+1])
                return 2; // 无解
        return 1; // 有无穷多组解
    }

    for (int i = n ; i >= 1; i -- )
        for (int j = i + 1; j <= n; j ++ ) 
            a[i][n+1]^=a[i][j]*a[j][n+1],a[i][j]=0;

    return 0; // 有唯一解
}


int main()
{
    //若不是m元线性方程组，则补充行或列
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n + 1; j ++ )
            scanf("%d", &a[i][j]);

    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Multiple sets of solutions");
    else
    {
        for (int i = 1; i <= n; i ++ )
            printf("%d\n", a[i][n+1]);
    }

    return 0;
}