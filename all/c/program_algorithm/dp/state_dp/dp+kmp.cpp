// acw1052 设计密码
#include <iostream>
#include <cstring>
using namespace std;
const int N=60;
const int mod=1e9+7;
char s[N],p[N];
int ne[N],f[N][N];
int main(){
    int n;
    scanf("%d %s",&n,p+1);
    int m=strlen(p+1);
    for (int i=2,j=0;i<=m;i++){
        while (j && p[i]!=p[j+1])   j=ne[j];
        if (p[i]==p[j+1]) j++;
        ne[i]=j;
    }
    f[0][0]=1;//f[i][j]到第i个位置，匹配到模式串第j个位置的方案数
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (char k='a';k<='z';k++){
                int u=j;
                while (u && k!=p[u+1])  u=ne[u];
                if (k==p[u+1])  u++;
                if (u<m)    f[i+1][u]=(f[i+1][u]+f[i][j])%mod;
                //因为这种图还是匹配简单，从后往前减一个字符，然后看在哪个位置很难解决
            }
        }
    }
    int ans=0;
    for (int i=0;i<m;i++)   ans=(ans+f[n][i])%mod;
    printf("%d",ans);
}