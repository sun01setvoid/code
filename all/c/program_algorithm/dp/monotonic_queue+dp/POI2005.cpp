//lg P3422
//以某个点为固定,后面的在动，应该从后往前做，因为不动的才是当前的k,其他的都是之前处理过的
//所以应该找前面的最小值，让他都比s[k]大
//单调队列是多个和单个比,多个在同一个方向
//注意控制判断和while出队的顺序
#include <iostream>
using namespace std;
const int N=1e6+10;
typedef long long ll;
int n;
int p[N],d[N],q[2*N];
ll sum[2*N];
bool ans[2*N];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>p[i]>>d[i];
        sum[i]=sum[i+n]=p[i]-d[i];
    }
    for (int i=1;i<=2*n;i++)    sum[i]+=sum[i-1];
    int hh=0,tt=-1;
    for (int i=2*n;i;i--){
        if (hh<=tt && q[hh]>i+n-1)   hh++;
        while (hh<=tt && sum[q[tt]]>=sum[i])    tt--;//找最小
        q[++tt]=i;
        if (i<=n){
            if (sum[q[hh]]-sum[i-1]>=0) ans[i]=true;//sum[0]=0;sum[i-1]因为第一个
        }//放在后面刚好可以把sum[i]放进去
    }
    d[0]=d[n];//因为d[i-1]
    for (int i=1;i<=n;i++)    sum[i]=sum[i+n]=p[i]-d[i-1];
    for (int i=1;i<=2*n;i++)    sum[i]+=sum[i-1];
    hh=0,tt=-1;
    for (int i=1;i<=2*n;i++){
        if (hh<=tt && q[hh]<i-n)  hh++;//最好存n+1个,不然因为处理不到最长的那段
        if (i>n){
            if (sum[i]-sum[q[hh]]>=0)  ans[i-n]=true;
        }//放在后面可能前面的被清空了
        while (hh<=tt && sum[q[tt]]<=sum[i])    tt--;//找最小
        q[++tt]=i;
    }
    for (int i=1;i<=n;i++){
        if (ans[i]) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
}