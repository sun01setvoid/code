//优化 转化为求最长子序列（条件:元素各不相同），按下标求最长下标子序列
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[N],b[N],idx[N],q[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)  cin>>a[i],idx[a[i]]=i;
    for (int i=1;i<=n;i++)  cin>>b[i],b[i]=idx[b[i]];
    int len=0;
    for (int i=1;i<=n;i++){
        int l=0,r=len;
        q[0]=-2e9;
        while (l<r){
            int mid=(l+r+1)>>1;
            if (q[mid]<b[i])
                l=mid;
            else r=mid-1;
        }
        q[l+1]=b[i];
        len=max(l+1,len);
    }
    cout<<len;
}
/*
//难以理解的dp(求最大值集合划分是可以重复的，只要不漏)(不会www)
//一序列前i个，二序列前j个的公共子序列（属性为max)
//划分有（00）f[i-1][j-1] (01)注意这里取f[i-1][j],不是01情况，但包含01的情况,且f[i][j]包含了f[i-1][j]，同理（10）f[i][j-1],(11)f[i-1][j-1]+1;
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int f[N][N];
int main(){
    int n;
    int  a[N],b[N];
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
       for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if (a[i]==b[j])
                    f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][n];
}
*/