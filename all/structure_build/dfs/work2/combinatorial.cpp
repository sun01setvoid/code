#include <iostream>
#include <vector>
using namespace std;
const int N=22;
string p[N];
vector <string> ans;
int n;
void dfs(int x,int l){
    if(!l){
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    if (x==n+1) return;
    dfs(x+1,l);
    ans.push_back(p[x]);
    dfs(x+1,l-1);
    ans.pop_back();
}

int main(){
    int m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)  cin>>p[i];
    dfs(1,m);
}
