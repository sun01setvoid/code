#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int st[510],match[510],res,n1,n2,m;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
int find(int x){
    for (int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if (!st[j]){
            st[j]=1;
            if (!match[j] || find (match[j])){
                match[j]=x;return 1;
            }
        }
    }
    return 0;
}
int main(){
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b);
    }
    for (int i=1;i<=n1;i++){
        memset(st,0,sizeof st);
        if (find(i))    res++;
    }
    cout<<res;
    system("pause");
}
