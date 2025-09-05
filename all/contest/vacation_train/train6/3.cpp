#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int vis[1010],v[1010];
int main(){
    int n;
    cin>>n;
    int a,h,m;
    char c,d;
    for (int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        memset(v,0,sizeof v);
        int cnt=0;int sum=0;
        while (cin>>a>>c>>h>>d>>m){
            if (a==0)   break;
            if (c=='S')    v[a]=h*60+m,vis[a]=1;//多次借同一本书???
            else if (vis[a] && c=='E') sum+=h*60+m-v[a],vis[a]=0,cnt++,v[a]=0;
        }
        cout<<cnt<<" ";
        if (cnt>0)
        cout<<(sum+cnt/2)/cnt<<endl;//四舍五入......
        else
        cout<<0<<endl;
    }
}