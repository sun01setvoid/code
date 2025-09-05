#include <iostream>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if (!b){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
signed main(){
    int x,y,m,n,L;
    int x0,y0;
    int a,b;
    cin>>x>>y>>m>>n>>L;
    if (x<y){
        a=m-n;
        b=y-x;
    }
    else{
        a=n-m;
        b=x-y;
    }
    if (a<0){a=-a,b=L-b;}
    int d=exgcd(a,L,x0,y0);
    if (b%d) {cout<<"Impossible";return 0;}
    x0=x0*b/d;
    int xd=L/d,yd=a/d;
    if (x0<0){
        x0+=(1-x0+xd-1)/xd*xd;//这里上取整
    }
    else{
        x0-=(x0-1)/xd*xd;
    }
    cout<<x0;
}