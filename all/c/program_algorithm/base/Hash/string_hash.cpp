//acw841字符串哈希
//跟进制一样，前面的位更高
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
const int P=131,N=1e5+10;
char s[N];
ULL h[N],p[N];//mod(2**64)
//h[i]表示从前i个字母的hash值
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}//确实说明反着是对的，这样才能让减出来的从0开始
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>s+1;
    p[0]=1;
    for (int i=1;i<=n;i++){
        h[i]=h[i-1]*P+s[i];
        p[i]=p[i-1]*P;
    }
    int l1,r1,l2,r2;
    while (m--){
        cin>>l1>>r1>>l2>>r2;
        if (get(l1,r1)==get(l2,r2)) puts("Yes");
        else    puts("No");
    }
}