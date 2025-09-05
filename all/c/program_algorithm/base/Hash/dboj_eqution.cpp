#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod=1000003;
int n,a,b,c,d,xv[200],head[mod],cnt;//头数组
struct data{int x,nxt,s;}g[mod];//x为值，nxt为下一个位置，s为标记
long long ans;
int Hash(int x)
{return (x%mod+mod)%mod;}
void insert(int x){
    int key=Hash(x);
  for (int i=head[key];i!=-1;i=g[i].nxt)
  {
  if (g[i].x==x)
  {g[i].s++;return;}
  }
  g[cnt].s=1; g[cnt].x=x;
  g[cnt].nxt=head[key]; head[key]=cnt++;
}
int search(int x){
    int key=Hash(x);
    for(int i=head[key];i!=-1;i=g[i].nxt){
        if(g[i].x==x)
        return g[i].s;
    }return 0;
}
void init()
{cnt=0;memset(head,-1,sizeof(head));ans=0;}
int main(){
    for(int i=1;i<=100;i++)
      xv[i]=i*i;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d)){
        if(a*b>0 && b*c>0 && c*d>0){puts("0");continue;}
      	init();
        for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)
          insert(xv[i]*a+xv[j]*b);//全部插入
        for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)
          ans+=search(-xv[i]*c-xv[j]*d);
        printf("%lld\n",ans*16);//16种排序
    }return 0;
}