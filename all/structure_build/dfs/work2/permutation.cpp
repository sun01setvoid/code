#include <iostream>
#include <vector>
using namespace std;
int vis[10],n;
vector <int> ans;
void dfs(int len){
    if (len==n){
        for (auto i:ans)    cout<<i<<" ";//for (int i=0;i<ans.size();i++)   cout<<ans[i]<<" ";
        cout<<endl;
        return ;
    }
    for (int i=1;i<=n;i++){
        if (!vis[i])    {
            vis[i]=1;ans.push_back(i);//填好该位置，用于处理下一个位置的状态
            dfs(len+1);//这里递归处理下层的情况
            vis[i]=0;ans.pop_back(); //回溯到该层最初状态,再继续改写这层
        }
    }
}
int main(){
    cin>>n;
    dfs(0);
}
