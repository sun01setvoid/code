#include <iostream>
using namespace std;
const int N=3e5+10;
int p[N];
int find (int x){
    if (p[x]!=x)    p[x]=find(p[x]);
    return p[x];
}
int main(){
    int t,n,tmp;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)  p[i]=i;
        for (int i=1;i<=n;i++){
            cin>>tmp;
            if (i+tmp<=n){
                int px=find(i),py=find(i+tmp);
                if (px!=py) p[px]=py;  
            }
            if (i-tmp>=1){
                int px=find(i),py=find(i-tmp);
                if (px!=py) p[px]=py;
            }
        }
        int cnt=0;
        for (int i=1;i<=n;i++)  if (p[i]==i)    cnt++;
        cout<<cnt-1<<endl;
    }
}