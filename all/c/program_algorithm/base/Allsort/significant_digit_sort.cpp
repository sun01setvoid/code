//基数排序
//对数据特征有要求
//从小个位数开始排，保证关系，再到更大的位数
//<=0几个，<=1几个，<=2几个
//每次运行完，每个<=x的位置减一
//提取数字bits是arr在BASE进制下有几位，(num/offset)%10提取数字
//正数BASE进制，负数，需要找最小值，然后减一下，转化(保证不溢出)
//可调BASE->趋向于桶排序
//若是从小到大排，要从后往前刷，保证大的数字先插入，因为是先放在后面的位置
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10,BASE=10;
int a[N],help[N],cnt[N];
void base_sort(int *a,int n,int bits){
    for (int offset=1;bits>0;offset*=BASE,bits--){
        memset(cnt,0,sizeof cnt);
        for (int i=1;i<=n;i++)  cnt[a[i]/offset%BASE]++;
        for (int i=1;i<BASE;i++)  cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--)  help[cnt[a[i]/offset%BASE]--]=a[i];
        for (int i=1;i<=n;i++)  a[i]=help[i];
    }
}
int main(){
    int n,ma=-0x3f3f3f3f;
    cin>>n;
    for (int i=1;i<=n;i++)  cin>>a[i],ma=max(a[i],ma);
    int bits=0;
    while (ma){
        bits++;
        ma/=10;
    }
    base_sort(a,n,bits);
    for (int i=1;i<=n;i++)  cout<<a[i]<<" ";
    /*
        int mi=0x3f3f3f3f;
        for (int i=1;i<=n;i++)  mi=min(mi,a[i]);
        for (int i=1;i<=n;i++)  a[i]=a[i]-min;
    */
}