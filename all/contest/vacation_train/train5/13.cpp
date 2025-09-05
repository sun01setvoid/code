#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef pair <int,int> PII;
bool cmp(int a,int b){
    return a>b;
}
int tr[1200000];
int main(){
    int n;
    cin>>n;
    int a[30],b[30];
    set <int> S;
    map <int,int> mp;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort (b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++){
        mp[b[i]]=i;
    }
    tr[1]=a[1];
    S.insert(1);
    for (int i=2;i<=n;i++){
        int cur=1;
        while(true){
            if (mp[a[i]]<mp[tr[cur]])    cur=cur*2;
            else    cur=cur*2+1;
            if (!tr[cur])    {tr[cur]=a[i];S.insert(cur);break;}
        }
    }
    queue <PII> q;
    q.push({tr[1],1});
    while (q.size()){
        auto t=q.front();
        q.pop();
        int id=t.second,v=t.first;
        if (id==1)    cout<<v;
        else cout<<" "<<v;
        if (tr[id*2])    q.push({tr[id*2],id*2});
        if (tr[id*2+1])    q.push({tr[id*2+1],id*2+1});
    }
    bool f=0;
    for (int i=1;i<=n;i++){
        if (!S.count(i))    {f=1;break;}
    }
    if (f)    cout<<endl<<"NO";
    else cout<<endl<<"YES";
}