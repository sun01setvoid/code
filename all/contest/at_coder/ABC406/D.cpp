#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    vector<int> sumx(h+1,0);
    vector<int> sumy(w+1,0);
    vector <set<int>> x(h+1),y(w+1);
    for (int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        sumx[a]++;
        sumy[b]++;
        x[a].insert(b);
        y[b].insert(a);
    }
    int q;
    cin>>q;
    while (q--){
        int a,b;
        cin>>a>>b;
        int ans=0;
        if (a==1){
            cout<<sumx[b]<<"\n";
            sumx[b]=0;
            if (x[b].size()==0) continue;
            for (auto it=x[b].begin();it!=x[b].end();it++){
                sumy[*it]--;
                y[*it].erase(b);
            }
            x[b].clear();
        }
        else{
            cout<<sumy[b]<<"\n";
            sumy[b]=0;
            if (y[b].size()==0) continue;
            for (auto it=y[b].begin();it!=y[b].end();it++){
                sumx[*it]--;
                x[*it].erase(b);
            }
            y[b].clear();
        }
    }
}