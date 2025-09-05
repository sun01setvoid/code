#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10, M = 8e6 + 10;
typedef pair<int, int> PII;
int dist[N];
int m,x,y;
string s[2];
const int INF = 0x3f3f3f3f3f3f3f3f;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int ls(int x){return 4*x;}
int rs(int x){return 4*x+1;}
int us(int x){return 4*x+2;}
int ds(int x){return 4*x+3;}
bool bfs() {
    for (int i=0;i<=4*m*4;i++) dist[i]=INF;
    dist[us(m+x)]=0;
    queue <PII> q;
    q.push({0,us(m+x)});
    while (!q.empty()) {
        auto [d, u] = q.front();
        q.pop();
        int x=u/4/m,y=u/4%m,pos=u%4;
        if (s[x-1][y]=='I') {
            if (pos==0) {
                if (y<=m-2 && dist[ls(x*m+y+1)]>d+1) dist[ls(x*m+y+1)]=d+1,q.push({ls(x*m+y+1),d+1});
            }else if (pos==1){
                if (y>=1 && dist[rs(x*m+y-1)]>d+1) dist[rs(x*m+y-1)]=d+1,q.push({rs(x*m+y-1),d+1});
            }
            else if (pos==2){
                if (x<=1 && dist[us((x+1)*m+y)]>d+1) dist[us((x+1)*m+y)]=d+1,q.push({us((x+1)*m+y),d+1});
            }
        }
        else{
            if (pos==0) {
                if (x<=1 && dist[us((x+1)*m+y)]>d+1) dist[us((x+1)*m+y)]=d+1,q.push({us((x+1)*m+y),d+1});
                if (x>=2 && dist[ds((x-1)*m+y)]>d+1) dist[ds((x-1)*m+y)]=d+1,q.push({ds((x-1)*m+y),d+1});
            }else if (pos==1){
                if (x<=1 && dist[us((x+1)*m+y)]>d+1) dist[us((x+1)*m+y)]=d+1,q.push({us((x+1)*m+y),d+1});
                if (x>=2 && dist[ds((x-1)*m+y)]>d+1) dist[ds((x-1)*m+y)]=d+1,q.push({ds((x-1)*m+y),d+1});
            }
            else if (pos==2){
                if (y>=1 && dist[ rs(x*m+y-1)]>d+1) dist[ rs(x*m+y-1)]=d+1,q.push({rs(x*m+y-1),d+1});
                if (y<=m-2 && dist[ls(x*m+y+1)]>d+1) dist[ls(x*m+y+1)]=d+1,q.push({ls(x*m+y+1),d+1});
            }else {
                if (y>=1 && dist[ rs(x*m+y-1)]>d+1) dist[ rs(x*m+y-1)]=d+1,q.push({rs(x*m+y-1),d+1});
                if (y<=m-2 && dist[ls(x*m+y+1)]>d+1) dist[ls(x*m+y+1)]=d+1,q.push({ls(x*m+y+1),d+1});
            }
        }
    }
    
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >>m >> x >> y;
        cin>>s[0]>>s[1];
        cout << (bfs()?"YES":"NO") << '\n';
    }
}
