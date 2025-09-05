#include <iostream>
using namespace std;
int a[1000010];
struct Node{
    int win;
    int lose;
}tr[1000010];//结构体！！！！
int n;
bool dfs(int u){
    if (u>n)    return true;
    if (tr[u].win<tr[u].lose)    return false;
    tr[2*u].win=tr[u].lose;
    tr[2*u+1].win=tr[u].win;
    if (dfs(2*u+1) && dfs(2*u))    return true;
    swap(tr[2*u].win,tr[2*u+1].win);
    if (dfs(2*u+1) && dfs(2*u))    return true;
    return false;
}
int main(){
    int k=3;
    cin>>k;
    n=(1<<k)-1;
    for (int i=k;i>=1;i--){
        for (int j=1<<(i-1);j<1<<i;j++)
            cin>>tr[j].lose;
    }
    cin>>tr[1].win;
    if (dfs(1)){
        cout<<tr[1<<(k-1)].win<<" "<<tr[1<<(k-1)].lose;
        for (int j=(1<<(k-1))+1;j<1<<k;j++)
            cout<<" "<<tr[j].win<<" "<<tr[j].lose;
    }
    else
        cout<<"No Solution";
}