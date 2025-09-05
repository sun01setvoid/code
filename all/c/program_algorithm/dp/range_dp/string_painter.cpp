//lg UVA1437
//类似于 难懂！！！
//直接把A刷成B问题可能在于一直取得是min
//如果是abb->bbb,就是0了，但是实际上左端点也是要更新的，不能因为A右端点与B右端点一样，就处理
#include <iostream>
#include <cstring>
using namespace std;
int dp[110][110];
int main(){     //先空字符串转换更好，因为要分别考虑空字符串和要转换成的字符串的问题
    string a,b;
    while (cin>>a>>b){
        string A="#",B="#";
        A+=a,B+=b;
        int l=a.size();
        memset(dp,0x3f,sizeof dp);
        for (int i=1;i<=l;i++)  dp[i][i]=1;
        for (int len=2;len<=l;len++){
            for (int i=1;i<=l-len+1;i++){
                int j=i+len-1;
                if (B[i]==B[j]) dp[i][j]=dp[i+1][j];
                else
                    for (int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
                    }
            }
        }
        dp[1][0]=0;//边界
        for (int i=1;i<=l;i++){
            if (A[i]==B[i]) dp[1][i]=dp[1][i-1];//这里有边界，也可以分类讨论
            else
                for (int k=1;k<i;k++){
                    dp[1][i]=min(dp[1][k]+dp[k+1][i],dp[1][i]);
                }
        }
        printf("%d\n",dp[1][l]);
    }
}
/*
int main(){
    string a,b;
    while(cin>>a>>b){
        string A="#",B="#";
        A+=a,B+=b;
        int l=a.size();
        memset(dp,0x3f,sizeof dp);
        for(int i=1;i<=l;i++){
            if (A[i]==B[i]) dp[i][i]=0;
            else dp[i][i]=1;
        }
        //直接转换呢？
        for (int len=2;len<=l;len++){
            for (int i=1;i<=l-len+1;i++){
                int j=i+len-1;
                if (B[i]==B[j]) dp[i][j]=min(dp[i][j-1],dp[i][j]),dp[i][j]=min(dp[i+1][j],dp[i][j]);
                if (A[j]==B[j]) dp[i][j]=min(dp[i][j-1],dp[i][j]);
                else if (A[i]==B[i])    dp[i][j]=min(dp[i+1][j],dp[i][j]);
                else {
                    for (int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
                    }
                }
            }
        }
        cout<<dp[1][l]<<endl;
        //从空字符串转换

        //从A转换
    }
}
*/