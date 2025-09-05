#include <iostream>
using namespace std;
int tr[40],a[40],n;
int lc=1;
void dfs(int u){
    tr[u]=a[lc];
    if (u*2+1<=n)    ++lc,dfs(u*2+1);
    if (u*2<=n)      ++lc,dfs(u*2);
}
int main(){
    cin>>n;
    for (int i=n;i>=1;i--)    cin>>a[i];
    dfs(1);
    cout<<tr[1];
    for (int i=2;i<=n;i++)    cout<<" "<<tr[i];
}
//完全二叉树节点位置由层序遍历决定,也就是2*i,2*i+1是他的左右节点，也就是可以判断出节点是否存在
//完全二叉树后序遍历我们由递归反推,完全可以知道他那些左右结点存在
//即根右左
//如果给前序遍历，直接按照前序遍历走就好