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
    for (int i=1;i<=W;i++)  dp[i]=-INF;// dp[0]=0;
    for (int i=1;i<=N;i++)
        for(int j=W;j>=0;j--){
            if (j+cow[i].w>=W) dp[W]=max(dp[W],dp[j]+cow[i].y);//因为背包无限,所以计算包含当前物品的价值与不包含时，要用j+col[i].w
            else dp[j+cow[i].w]=max(dp[j+cow[i].w]+cow[i].y,dp[j]);
        }
    return dp[W]<0;
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