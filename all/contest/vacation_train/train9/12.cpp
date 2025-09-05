#include <iostream>
using namespace std;
int mp[10][10];
int n,l;
int visc[5],visr[5];
int cnt=0;
void dfs(int x,int y){
    if (x==n && y==0)    {
        cnt++;return;//找有多少的最好固定一个方向查询，如果是上下左右无脑搜索可能会重复，或者你也可以把终点的状态记下来
    }//越出边界将最后一个填上，也可以不填，可以直接推出
    int yi=(y+1)%n,xi=x+(y+1)/n;//一行一行填！
    for (int i=0;i<=l-visr[x] && i<=l-visc[y];i++){
        if (x==n-1){
            if (i+visc[y]!=l) continue;
        }//满足条件才执行,每一次都是循环找值，这只是在循环中给予条件
        if (y==n-1){
            if (i+visr[x]!=l)   continue;
        }//满足条件才执行
        mp[x][y]+=i;
        visc[y]+=i;
        visr[x]+=i;
        dfs(xi,yi);
        mp[x][y]-=i;
        visc[y]-=i;
        visr[x]-=i;
    }//能找到值，才继续遍历//更改当前点的不同值往下走
}
int main(){
    cin>>l>>n;
    dfs(0,0);
    cout<<cnt;
}