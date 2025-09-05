//两两互质，中国剩余
#include <iostream>
using namespace std;
typedef __int128 LL;
const int N = 15;
void exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
    return;
}

int main(){
    int n;
    cin>>n;
    int m[N], a[N];
    LL M = 1;
    for(int i = 0; i < n; i++){
        cin>>m[i]>>a[i];
        M *= m[i];
    }
    LL ans = 0;
    for(int i = 0; i < n; i++){
        LL x, y;
        exgcd(M / m[i], m[i], x, y);//Mi=M/mi,求Mi-1(关于mi)(扩欧)，mi是质数的话的话也可以用费马小定理
        ans = (ans + a[i] * M / m[i] * x) % M;

    }
    ans = (ans + M) % M;
    //通解为k*lcm+ans(最小整数解)
    printf("%lld", ans);
    return 0;
}