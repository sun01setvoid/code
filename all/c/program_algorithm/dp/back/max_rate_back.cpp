//lg P4377
#include  <iostream>
using namespace std;
int N,W;
const int INF=0x3f3f3f3f;
struct Node{
    int w;
    int t;
    double y;
}cow[300];
double dp[1010];
//dp[j]表示背包为j时的最大价值，>=w记作dp[w]
bool check(double x){           //O(nlogn)
    for (int i=1;i<=N;i++)  cow[i].y=cow[i].t-cow[i].w*x;
    for (int i=1;i<=W;i++)  dp[i]=-INF;// dp[0]=0;//设为负无穷，是因为求的是最大价值
    /*
    for (int i=1;i<=N;i++){
        for(int j=W;j>=cow[i].w;j--){          //一种是到0叠加每一个重量,可用于最大值不确定的时候，限制条件为>=W;一种是到w[i]减去每一个容量,正常逻辑
            //if (j+cow[i].w>=W)  dp[W]=max(dp[W],dp[j]+cow[i].y);//大于等于W的由他们来更新
            //由此一步直接卡掉了原来的,j最小应该到0,所以不如从0到W,求dp[j+cow[i].w]
            dp[j]=max(dp[j],dp[j-cow[i].w]+cow[i].y);
        }
        if (cow[i].w>W)
        dp[W]=max(dp[0]+cow[i].y,dp[W]);
    }
    */       //会卡掉，体积不够，导致没有从dp[0]更新
    /*
    for (int i=1;i<=N;i++)
        for(int j=W;j>=0;j--){
            if (j+cow[i].w>=W) dp[W]=max(dp[W],dp[j]+cow[i].y);
            else dp[j+cow[i].w]=max(dp[j]+cow[i].y,dp[cow[i].w+j]);
        }
    return dp[W]<0;
    */
}
int main(){
    cin>>N>>W;
    double l=0,r=0;
    for (int i=1;i<=N;i++){
        cin>>cow[i].w>>cow[i].t;
        r+=cow[i].t;
    }
    for (int i=0;i<50;i++){
        double m=(l+r)/2;
        if (check(m))   r=m;
        else l=m;
    }
    cout<<(int)(l*1000+0.0001)<<endl;
    return 0;
}