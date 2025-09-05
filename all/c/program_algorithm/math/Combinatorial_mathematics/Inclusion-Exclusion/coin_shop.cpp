//lg p1450
//dp[i]，i元无限制方法数，若每个硬币有限制，可以无限-不合理的
//假设2元5个超了，则dp[n-6*2]就是花超的方法数
//刚好违规的方案对应这种方法，违规考虑不管怎么样都会违规的方法数
//dp[n]-违规1U违规2U违规3U违规4
//dp表可以反应交集
#include <iostream>
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL dp[N],c[5],d[5];
int main(){
    int n,s;
    cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
    dp[0]=1;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=100000;j++)
            if (j>=c[i])
            dp[j]=dp[j]+dp[j-c[i]];
    }
    while (n--){
        cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
        LL ans=0;
        for (int i=1;i<=15;i++){//0000不需要
            LL t=s;
            int sign=-1;
            for (int j=0;j<=3;j++){
                if ((i>>j)&1==1){
                    t-=c[j+1]*(d[j+1]+1);
                    sign=-sign;
                }
            }
            if (t>=0)   ans+=sign*dp[(int)t];
        }
        cout<<dp[s]-ans<<endl;
    }
}