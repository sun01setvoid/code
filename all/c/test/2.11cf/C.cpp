#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll get(ll x){
    ll num=1;
    while (x--){//+1
        num*=10;
    }
    return num;
}
ll sev(ll x){//
    ll num=17;
    while (x--){
        num*=10;
    }
    return num;
}
ll eie(ll x){//
    ll num=18;
    while (x--){
        num*=10;
    }
    return num;
}
ll nin(ll x){
    ll sum=0;
    if (x==0)   return 1;
    while (x--){
        sum=sum*10+9;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    int temp;
    int a[20];
    while (t--){
        cin>>temp;
        ll num=temp;
        ll l=0,d,flag=0;
        while (temp){
            d=temp%10;
            l+=1;
            if (d==7)   {flag=1;break;}
            temp/=10;
        }
        if (flag)   {cout<<0<<endl;continue;}
        int cnt=0;
        ll w=get(1),v=get(0);ll dv1,dv2;
        temp=num%10;
        if (temp>7) a[cnt]=temp-7;
        else    a[cnt]=temp+3;
        for (cnt=1;cnt<l;cnt++){
            w=get(cnt+1),v=get(cnt);
            dv1=nin(cnt),dv2=nin(cnt+1);
            temp=num%w;
            if (temp<7*v)   a[cnt]=min(((7*v-temp)+dv1-1)/dv1,(8*v-temp-1)/dv1);
            else{
                a[cnt]=min(((sev(cnt)-temp)+dv2-1)/dv2,(eie(cnt)-temp-1)/dv2);
            }
        }
        int mi=a[0];
        for (int i=1;i<cnt;i++){
            if (mi>a[i])    mi=a[i];
        }
        cout<<mi<<endl;
    }
}