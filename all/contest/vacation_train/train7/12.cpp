#include <iostream>
#include <vector>
using namespace std;
double g[1010][1010];
int vis[1010];
int main(){
    int n,m,k;
    cin>>n>>m;
    string temp;int tmp;
    for (int i=1;i<=m;i++){
        cin>>k;
        vector <int> vc;
        for (int j=1;j<=k;j++){
            cin>>temp;
            //0
            if (temp[0]=='-')    tmp=-stoi(temp),vis[tmp]=0;
            else   tmp=stoi(temp),vis[tmp]=1;
            vc.push_back(tmp);
        }
        int l=vc.size();
        for (int i=0;i<l;i++){
            for (int j=i+1;j<l;j++)    g[vc[j]][vc[i]]=g[vc[i]][vc[j]]+=1.0/k;
        }
    }
    string a,b;
    int x,y;
    cin>>a>>b;
    if (a[0]=='-')    x=-stoi(a),vis[x]=0;
    else  x=stoi(a),vis[x]=1;
    if (b[0]=='-')    y=-stoi(b),vis[y]=0;
    else   y=stoi(b),vis[y]=1;
    double ma=0,mb=0;
    for (int i=0;i<=n-1;i++){
        if (vis[x]!=vis[i] && g[x][i]>ma )   ma=g[x][i];
    }
    for (int i=0;i<=n-1;i++){
        if (vis[y]!=vis[i] && g[y][i]>mb )   mb=g[y][i];
    }
    vector <int> ans1;
    vector <int> ans2;
    bool f1=0,f2=0;
    for (int i=0;i<=n-1;i++){
        if (vis[x]!=vis[i] && abs(g[x][i]-ma)<0.00001){
            if (i==y) f1=1;
            ans1.push_back(i);
        }
    }
    for (int i=0;i<=n-1;i++){
        if (vis[y]!=vis[i] && abs(g[y][i]-mb)<0.00001){
            if (i==x) f2=1;
            ans2.push_back(i);
        }
    }
    if (f1==1 && f2==1)   cout<<a<<" "<<b;
    else {
        if (vis[x]==0){
            for (int i=0;i<ans1.size();i++)    cout<<a<<" "<<ans1[i]<<endl;
        }
        else{
            for (int i=0;i<ans1.size();i++)    cout<<a<<" "<<"-"+to_string(ans1[i])<<endl;
        }
        if (vis[y]==0){
            for (int i=0;i<ans2.size();i++)    cout<<b<<" "<<ans2[i]<<endl;
        }
        else{
            for (int i=0;i<ans2.size();i++)    cout<<b<<" "<<"-"+to_string(ans2[i])<<endl;
        }
    }
}