#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+10;
int n;
int tr[N];
int lowbit(int x){
    return x&-x;
}
void add(int x,int c){
    for (int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x){
    int res=0;
    for (int i=x;i;i-=lowbit(i))    res+=tr[i];
    return res;
}
int main(){
    int temp;
    long long ans;
    while (cin>>n){
        ans=0;
        memset(tr,0,sizeof tr);
        for (int i=1;i<=n;i++){
            cin>>temp;
            add(temp,1);//这个数的个数
            ans+=sum(n)-sum(temp);//比他大的范围内的数的个数，所以是单点修改，区间求和，用树状数组
        }
        cout<<ans<<endl;//注意数据范围开long long
    }
}