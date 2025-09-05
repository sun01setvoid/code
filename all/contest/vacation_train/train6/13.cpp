#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
typedef pair <int,int> PII;
struct Node{
    int l=-1,r=-1;
    int v;
}tr[1010];//cnt递增决定其左右节点
//first,d  second,fa
map <int,PII> mp1;
void dfs(int x){
    if (tr[x].l!=-1)    {int pos=tr[x].l;mp1[tr[pos].v].first=mp1[tr[x].v].first+1,mp1[tr[pos].v].second=tr[x].v;dfs(pos);}
    if (tr[x].r!=-1)    {int pos=tr[x].r;mp1[tr[pos].v].first=mp1[tr[x].v].first+1,mp1[tr[pos].v].second=tr[x].v;dfs(pos);}
}
int main(){
    int n;
    cin>>n;
    int a[110],b[110];
    map <int,int> mp;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    int cnt=1;
    tr[cnt].v=a[1];
    //实际上不用中序遍历,小于就插入到左子树，大于就插入右子树
    for (int i=2;i<=n;i++){
        int cur=1;
        while(true){
            if (a[i]<tr[cur].v){
                if (tr[cur].l==-1){
                    tr[cur].l=++cnt;
                    tr[cnt].v=a[i];
                    break;
                }
                cur=tr[cur].l;
            }
            else{
                if (tr[cur].r==-1){
                    tr[cur].r=++cnt;
                    tr[cnt].v=a[i];
                    break;
                }
                cur=tr[cur].r;
            }
        }
    }
    mp1[tr[1].v].second=tr[1].v;
    mp1[tr[1].v].first=0;
    dfs(1);
    int m,x,y;
    cin>>m;
    string s,temp;
    getchar();
    while (m--){
        getline(cin,s);
        stringstream s1(s);
        vector <string> vc;
        while (s1>>temp){
            vc.push_back(temp);
        }
        int vol=vc.size();
        if (vol==4){
           x=stoi(vc[0]);
            if (!mp.count(x))    {cout<<"No"<<endl;continue;}
            if (mp1[x].second==x)    cout<<"Yes"<<endl;
            else    cout<<"No"<<endl;
        }
        else if (vol==8){
            x=stoi(vc[0]),y=stoi(vc[2]);
            if (!mp.count(x) || !mp.count(y))    {cout<<"No"<<endl;continue;}
            if (mp1[x].first==mp1[y].first)    cout<<"Yes"<<endl;
            else    cout<<"No"<<endl;
        }
        else if (vol==5){
            x=stoi(vc[0]),y=stoi(vc[2]);
            if (!mp.count(x) || !mp.count(y))    {cout<<"No"<<endl;continue;}
            if (x!=y && mp1[x].second==mp1[y].second)    cout<<"Yes"<<endl;
            else    cout<<"No"<<endl;
        }
        else if (vc.size()==6){
            x=stoi(vc[0]),y=stoi(vc[5]);
            if (!mp.count(x) || !mp.count(y))    {cout<<"No"<<endl;continue;}
            if (x!=y && mp1[y].second==x)    cout<<"Yes"<<endl;
            else    cout<<"No"<<endl;
            //因为把根节点的父亲设成了自己所以判断父亲是，要注意他们必须不相同
        }
        else{
            if (vc[3]=="left"){
                x=stoi(vc[0]),y=stoi(vc[6]);
                if (!mp.count(x) || !mp.count(y))    {cout<<"No"<<endl;continue;}
                if (mp1[x].second==y && x<y)    cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            else if (vc[3]=="right"){
                x=stoi(vc[0]),y=stoi(vc[6]);
                if (!mp.count(x) || !mp.count(y))    {cout<<"No"<<endl;continue;}
                if (mp1[x].second==y && x>y)    cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
}