#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    while(t--){
        int n,m,k;
        cin>>n>>m;
        vector <vector<int>> mp(n,vector<int>(m));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>mp[i][j];
            }
        }
        cin>>k;
        while (k--){
            string s;
            cin>>s;
            vector <vector<int>> ans(n,vector<int>(m,0));
            vector <vector<int>> vis(n,vector<int>(m,0));
            if (s[0]=='L'){
                for (int i=0;i<n;i++){
                    int pos=-1;
                    for (int j=0;j<m;j++){
                        if (mp[i][j]!=0){
                            ans[i][++pos]=mp[i][j];
                            if (pos>=1 && ans[i][pos]==ans[i][pos-1] && vis[i][pos-1]==0){
                                ans[i][pos-1]=2*mp[i][j];
                                ans[i][pos]=0,vis[i][pos]=0;
                                vis[i][pos-1]=1;
                                --pos;
                            }
                        }
                    }
                }
            }
            else if (s[0]=='R'){
                for (int i=0;i<n;i++){
                    int pos=m;
                    for (int j=m-1;j>=0;j--){
                        if (mp[i][j]!=0){
                            ans[i][--pos]=mp[i][j];
                            if (pos<=m-2 && ans[i][pos]==ans[i][pos+1] && vis[i][pos+1]==0){
                                ans[i][pos+1]=2*mp[i][j];
                                ans[i][pos]=0,vis[i][pos]=0;
                                vis[i][pos+1]=1;
                                ++pos;
                            }
                        }
                    }
                }
            }
            else if (s[0]=='U'){
                for (int j=0;j<m;j++){
                    int pos=-1;
                    for (int i=0;i<n;i++){
                        if (mp[i][j]!=0){
                            ans[++pos][j]=mp[i][j];
                            if (pos>=1 && ans[pos][j]==ans[pos-1][j] && vis[pos-1][j]==0){
                                ans[pos-1][j]=2*mp[i][j];
                                ans[pos][j]=0,vis[pos][j]=0;
                                vis[pos-1][j]=1;
                                --pos;
                            }
                        }
                    }
                }
            }
            else if (s[0]=='D'){
                for (int j=0;j<m;j++){
                    int pos=n;
                    for (int i=n-1;i>=0;i--){
                        if (mp[i][j]!=0){
                            ans[--pos][j]=mp[i][j];
                            if (pos<=n-2 && ans[pos][j]==ans[pos+1][j] && vis[pos+1][j]==0){
                                ans[pos+1][j]=2*mp[i][j];
                                ans[pos][j]=0,vis[pos][j]=0;
                                vis[pos+1][j]=1;
                                ++pos;
                            }
                        }
                    }
                }
            }
            mp=ans;
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    cout<<mp[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
}