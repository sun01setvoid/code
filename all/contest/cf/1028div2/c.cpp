#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int dist[N];
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dist,0x3f,sizeof dist);
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        int d = a[0];
        for (int i = 1; i < n; ++i)
        {
            d = gcd(d, a[i]);
        }
        queue<int> q;
        int steps = 0;
        int cnt=0;
        for (int &x:a) {
            if (x==d) cnt++;  
            dist[x]=0;
            q.push(x);
        }
        if (cnt) cout<<n-cnt<<endl;
        else {
            while (!q.empty()){
                int g=q.front();
                q.pop();
                if (g==d) {break;}
                for (int &x:a){
                    int td=gcd(x,g);
                    if (dist[td]==0x3f3f3f3f) dist[td]=dist[g]+1,q.push(td);
                }
            }
            cout<<dist[d]+n-1<<endl;
        }
    }
    return 0;
}