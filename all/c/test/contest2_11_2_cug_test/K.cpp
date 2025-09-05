#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,k,v[110];
typedef pair<int,int > PII;
int main(){
    priority_queue <PII,vector<PII>,greater <PII> > q;
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++){
        cin>>v[i];
        q.push({v[i],i});
    }
    int ver,cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (k-cnt>=n-i+1){
                auto t=q.top();
                q.pop();
                cout<<t.second<<" ";
                cnt++;
            }
            else cout<<0<<" ";
        }
        cout<<endl;
    }
    system("pause");
}