//exgcd使得求逆元时MOD不是质数时成立
#include <iostream>
using namespace std;
typedef long long LL;
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,a,b,m,x,y;
    cin>>n;
    while (n--){
        cin>>a>>b>>m;
        int d=exgcd(a,m,x,y);
        if (b%d)    cout<<"impossible\n";
        else{
            cout<<(LL)b/d*x%m<<"\n";
        }
    }
}