#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1e5+10;
vector<int> G[N];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector <int> p(n+1,1e5+10);
        for (int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            p[a]=min(p[a],b);
            p[b]=min(p[b],a);
        }
        bool flag=0;
        for (int i=1;i<=n;i++){
            if (p[i]>=i) {
                flag=1;
                break;
            }
        }
        if (flag) cout<<"0\n";
        else cout<<"1\n";
    }
}