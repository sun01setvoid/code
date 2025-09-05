#include <iostream>
using namespace std;
#define int long long
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
signed main(){
    int t;
    int n,x,y,vx,vy;
    cin>>t;
    int a,b;
    while (t--){
        cin>>n>>x>>y>>vx>>vy;
        int d0=exgcd(vx,vy,a,b);
        vx=vx/d0,vy=vy/d0;
        int d=exgcd(vy,n,a,b);
        //cout<<"d="<<d<<"\n";
        int d1=n/d;
        //cout<<"d1="<<d1<<"\n";
        if (-y%d!=0){
            cout<<"-1"<<"\n";
            continue;
        }
        int x0=((-y/d*a)%d1+d1)%d1;
        //cout<<"x0="<<x0<<"\n";
        d=exgcd(vx*d1,n,a,b);
        //cout<<"d="<<d<<"\n";
        if ((-x-vx*x0)%d!=0){
            cout<<"-1"<<"\n";
            continue;
        }
        int d2=n/d;
        //cout<<"d2="<<d2<<"\n";
        int x1=(((-x-vx*x0)/d*a)%d2+d2)%d2;
        //cout<<"x1="<<x1<<"\n";
        int x2=((x0+d1*x1)%(d1*d2)+d1*d2)%(d1*d2);
        //cout<<"x2="<<x2<<"\n";
        a=(x+vx*x2)/n,b=(y+vy*x2)/n;
        //cout<<"a="<<a<<" b="<<b<<"\n";
        cout<<a-1+b-1+(a+b)/2+abs(a-b)/2<<"\n";
    }
}