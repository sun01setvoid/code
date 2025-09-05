//O(n**3)
//高斯消元
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];
//从1开始
int gauss()  
{
    int c, r;
    for (c = 1, r = 1; c <= n; c ++ )
    {
        int t = r;
        for (int i = r; i <= n; i ++ )  // 找绝对值最大的行,一是防止溢出，而是刚好找是否有非零行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;//如果是零，这一列不算，但是这行还要算

        for (int i = c; i <= n + 1; i ++ ) swap(a[t][i], a[r][i]);  // 将绝对值最大的行换到最顶端
        for (int i = n + 1; i >= c; i -- ) a[r][i] /= a[r][c];  // 将当前行的首位变成1
        for (int i = r + 1; i <= n; i ++ )  // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n + 1; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];
        r ++ ;
    }

    if (r < n + 1)
    {
        for (int i = r; i <= n; i ++ )
            if (fabs(a[i][n+1]) > eps)
                return 2; // 无解
        return 1; // 有无穷多组解
    }

    for (int i = n ; i >= 1; i -- )
        for (int j = i + 1; j <= n; j ++ ) //清零n*n上非主元的元素
            a[i][n+1] -= a[i][j] * a[j][n+1],a[i][j]=0;//a[i][j]是后面的1乘的,这里按行看

    return 0; // 有唯一解
}


int main()
{
    //若不是m元线性方程组，则补充行或列
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n + 1; j ++ )
            scanf("%lf", &a[i][j]);

    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else
    {
        for (int i = 1; i <= n; i ++ )
            printf("%.2lf\n", a[i][n+1]);
    }

    return 0;
}