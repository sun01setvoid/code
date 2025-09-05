#include <iostream>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int n,m,Size[N],p[N];
int find(int x){
    if (p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
    cin>>n>>m;
    int a,b,px,py;
    string s;
    for (int i=1;i<=n;i++)  {p[i]=i,Size[i]=1;}
    for (int i=0;i<m;i++){
        cin>>s>>a;
        px=find(a);
        if (s=="C") {
            cin>>b;py=find(b);
            if (px!=py){
                p[px]=py;
                Size[py]+=Size[px];
            }
        }
        else if (s=="Q1"){
            cin>>b;py=find(b);
            if (px==py) puts("Yes");
            else    puts("No");
        }
        else
            cout<<Size[px]<<endl;;
    }
}