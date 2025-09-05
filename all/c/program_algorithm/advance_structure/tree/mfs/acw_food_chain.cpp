#include <iostream>
#include <cstring>
using namespace std;
const int N=5e4+10;
int p[N],d[N],n,k,res;
int find (int x){//关于链式dfs的思考
    if(p[x]!=x){
        int u=p[x];
        p[x]=find(p[x]);
        d[x]+=d[u];
    }
    return p[x];
}
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)  p[i]=i;
    int q,x,y;
    for(int i=0;i<k;i++){
        cin>>q>>x>>y;
        if (x>n || y>n) {res++;continue;}
        else {//并查集取余做差判断关系，(转换到0就不会有正负数关系)，负数的族是(x%n+n)%n
            int px=find(x),py=find(y);
            if (q==1) {
                if (px==py)
                    {if ((d[x]-d[y])%3!=0)   res++;}
                else  {p[px]=py,d[px]=d[y]-d[x];}
            }
            else{
                if (px==py)
                    {if ((d[x]-d[y]-1)%3!=0) res++;}
                else    {p[px]=py,d[px]=d[y]-d[x]+1;}
            }
        }
    }
    cout<<res;
}