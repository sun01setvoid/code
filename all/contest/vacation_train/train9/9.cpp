#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e5+10;
vector <int> G[N];
int n,m;
int main(){
    int k,tmp,q;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>k;
        while (k--)    cin>>tmp,G[tmp].push_back(i);
        sort(G[tmp].begin(),G[tmp].end());
    }
    cin>>q;
    int x,y;
    while (q--){
        cin>>x>>y;
        int res=0;
        for (auto i:G[x]){
            if (binary_search(G[y].begin(),G[y].end(),i))    res++;
        }
        cout<<res<<endl;
    }
}