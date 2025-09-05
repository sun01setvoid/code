#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector <int> st;
ll f[21]={1};//double 更大,ll只到20
//一个数的排名是多少，看他前面有几个数，然后初始的(最前面的)那个排名+人数就是当前人的排名
//前面有多少人==跳多少步==离开了哪些人，到了哪
ll kangtuo(){
    int len=st.size();
    ll ans=0;//从0开始
    for (int i=0;i<len;i++){
        int cnt=0;
        for (int j=i+1;j<len;j++)//可以用树状数组或线段树标记数是否存在，查还剩多少个小的
            if (st[j]<st[i])    cnt++;//找后面有多少比他小的，那些小的都可以放在他位置，后面的任意排
        ans+=cnt*f[len-i-1];
    }
    return ans+1;//注意康托展开从0开始，所以字典序排名应该是ans+1;
}
int main(){
    for (int i=1;i<=20;i++) f[i]=f[i-1]*i;
    //输入vector中，scanf("%1d")
}