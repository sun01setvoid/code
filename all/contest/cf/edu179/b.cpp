#include <bits/stdc++.h>
using namespace std;
int main(){
    int p[11];
    p[1]=1,p[2]=2;
    for (int i=3;i<=10;i++) p[i]=p[i-1]+p[i-2];
    int t;
    cin>>t;
    while (t--){
        int a[3];
        int n,m;
        cin>>n>>m;
        while (m--){
            cin>>a[0]>>a[1]>>a[2];
            sort(a,a+3);
            if (a[2]>=p[n]+p[n-1] && a[1]>=p[n] && a[0]>=p[n]) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
}