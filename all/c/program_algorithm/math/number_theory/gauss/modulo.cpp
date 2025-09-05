//高斯消元同余方程组一般余一个质数，乘法逆元保证下有没有
#include <iostream>
using namespace std;
//O(n**3logn)    
//若自由元不操作或设为0则O(n*n*logn),其实log应该是C
using namespace std;

const int N = 110;
const double eps = 1e-8;
const int MOD=7;

int n;
int a[N][N],inv[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
//从1开始
int gauss()  
{
    int c, r;
    for (c = 1, r = 1; c <= n; c ++ )
    {
        int t = r;
        for (int i = r; i <= n; i ++ ){  // 找绝对值最大的行,一是防止溢出，而是刚好找是否有非零行
            if (a[i][c])
                t = i;
                break;
        }

        if (!a[t][c]) continue;//如果是零，这一列不算，但是这行还要算

        for (int i = c; i <= n + 1; i ++ ) swap(a[t][i], a[r][i]);  // 将绝对值最大的行换到最顶端
        for (int i = r + 1; i <= n; i ++ )  // 用当前行将下面所有的列消成0
            if (a[i][c]){
                int gcd_num=gcd(a[r][c],a[i][c]);
                int f1=a[r][c]/gcd_num,f2=a[i][c]/gcd_num;
                for (int j = n + 1; j >= c; j -- ){
                    a[i][j]=((a[i][j]*f1%MOD-a[r][j]*f2%MOD)%MOD+MOD)%MOD;
                }
            }
        //如果想在这一步就化为主元列上无其他非零元，那么注意向上删除的时候上方行的元素要变
        /*
        for (int i = 1; i <= n; i ++ )  // 用当前行将下面所有的列消成0
            if (i!=r && a[i][c]){
                int gcd_num=gcd(a[r][c],a[i][c]);
                int f1=a[r][c]/gcd_num,f2=a[i][c]/gcd_num;
                for (int j = n + 1; j >= 1; j -- ){
                    a[i][j]=((a[i][j]*f1-a[r][j]*f2)%MOD+MOD)%MOD;//因为这时候选中的主元前面的列都为0了，所以可以
                }
            }
        */
        r ++ ;
    }

    if (r < n + 1)
    {
        for (int i = r; i <= n; i ++ )
            if (a[i][n+1])
                return 2; // 无解
        return 1; // 有无穷多组解
    }

    //这里是全1化+列清零
    for (int i = n ; i >= 1; i -- ){
        for (int j = i + 1; j <= n; j ++ ){ //清零n*n上非主元的元素
            a[i][n+1]=((a[i][n+1]-a[i][j]*a[j][n+1]%MOD)%MOD+MOD)%MOD,a[i][j]=0;//a[i][j]是后面的乘的,这里按行看
            //因为先执行的主元都变1，所以接下来更新的时候那些行都只会*1，也就是不用变，且这里一定是满秩
        }
        a[i][n+1]=a[i][n+1]*inv[a[i][i]]%MOD,a[i][i]=1;
    }

    return 0; // 有唯一解
}

void init(){
    inv[1]=1;  for (int i=2;i<MOD;i++)    inv[i]=(MOD-MOD/i*inv[MOD%i])%MOD;
    //inv[i]=((MOD-MOD/i*inv[MOD%i])%MOD+MOD)%MOD;为什么不？
}
int main()
{
    //若不是m元线性方程组，则补充行或列
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n + 1; j ++ )
            scanf("%d", &a[i][j]);
    //最好先把系数化成非负
    init();
    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else
    {
        for (int i = 1; i <= n; i ++ )
            printf("%d\n", a[i][n+1]);
    }
    return 0;
}