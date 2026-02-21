#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl;
const int maxn=1e6+10;
int h[maxn];
int cnt=0;
void up(int u){
    while (u/2 && h[u/2]>h[u]){
        swap(h[u],h[u/2]);
        u/=2;
    }
}
void down(int u){
    int t=u;
    if (2*u<=cnt && h[2*u]<h[t]) t=2*u;
    if (2*u+1<=cnt && h[2*u+1]<h[t]) t=2*u+1;
    if (t!=u){
        swap(h[t],h[u]);
        down(t);
    }
}
int main(){
    int n;
    cin>>n;
    while (n--){
        int op;
        cin>>op;
        if (op==1){
            int x;
            cin>>x;
            h[++cnt]=x;
            up(cnt);
        }else if (op==2){
            cout<<h[1]<<endl;
        }else {
            h[1]=h[cnt--];
            down(1);
        }
    }
}