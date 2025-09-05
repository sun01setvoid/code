#include <iostream>
using namespace std;
int ans=0,di[19],n,ang;
void dfs(int a,int b,int c,int d,int step,int anger,int hurt,int flag){
    //bfs分层要写成队列（一个front,一个pop获取数据），dfs直接写递归（这种递归要注意他要不要分条件，有时候是不能写 if-else会无法构成树，直接if后结束了）；
    if (step==n+1){
        ans=max(ans,hurt);
        return;
    }//超出一步
    int s[4]={a,b,c,d};//处理状态
    for (int i=0;i<4;i++){
        if (s[i]!=0){
            s[i]=(s[i]+1)%3;
        }
    }
    if (a==0){
        dfs(a+1,s[1],s[2],s[3],step+1,anger,hurt+di[step]*flag,1);//简单的处理状态可以（应该）在参数列表中
    }//用原状态判断
    if (b==0){
        dfs(s[0],b+1,s[2],s[3],step+1,anger+ang,hurt,1);
    }
    if (c==0){
        dfs(s[0],s[1],c+1,s[3],step+1,anger,hurt+anger*flag,1);
    }
    if (d==0){
        dfs(s[0],s[1],s[2],d+1,step+1,anger,hurt,2);
    }
    return;
}
//如果用unsignded int 2**31 *3就回去了（好像找不到3次的）
int main(){
    cin>>n>>ang;
    for (int i=1;i<=n;i++){
        cin>>di[i];
    }
    dfs(0,0,0,0,1,0,0,1);
    cout<<ans;
    //多个状态的表示，还是隔着变化；
    getchar();
    getchar();
}