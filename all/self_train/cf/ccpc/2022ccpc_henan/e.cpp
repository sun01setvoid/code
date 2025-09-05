#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;string s;
bool solve(int i,int j,int k,vector <vector<int>>& pos){
    int st=-1;
    for (int t=0;t<=4;t++){
        auto it=lower_bound(pos[i].begin(),pos[i].end(),st+1);
        if (it==pos[i].end()) return false; 
        st=pos[i][it-pos[i].begin()];
    }
    for (int t=0;t<=6;t++){
        auto it=lower_bound(pos[j].begin(),pos[j].end(),st+1);
        if (it==pos[j].end()) return false; 
        st=pos[j][it-pos[j].begin()];
    }
    for (int t=0;t<=4;t++){
        auto it=lower_bound(pos[k].begin(),pos[k].end(),st+1);
        if (it==pos[k].end()) return false; 
        st=pos[k][it-pos[k].begin()];
    }
    return true;
}
int main(){
    vector <vector<int>> pos(26);
    cin>>n>>s;
    for (int i=0;i<n;i++){
        pos[s[i]-'a'].push_back(i);
    }
    bool f=0;
    int a,b,c;
    for (int i=0;i<=25;i++)
        for (int j=0;j<=25;j++)
            for (int k=0;k<=25;k++)
                if (solve(i,j,k,pos)){
                    f=1;a=i,b=j,c=k;break;
                }
    if (!f) cout<<"none";
    else{
        for(int t=0;t<=4;t++) cout<<(char)('a'+a);
        for (int t=0;t<=6;t++) cout<<(char)('a'+b);
        for (int t=0;t<=4;t++) cout<<(char)('a'+c);
    }
}