#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct Node {
    int lay;
    int fin;
};
struct dot{
    string id;
    string name;
    int time;
    int srt;//sort排序可能改变相同time顺序
}f[3010];
string a[30010],b[30010];
bool cmp(dot &x,dot& y){
    if (x.time!=y.time) return x.time<y.time;
    return x.srt<y.srt;
}
int main(){
    int day=1;
    int d,p;
    cin>>d>>p;
    int t,s;
    int h,m;
    int con;
    string name,id;
    map <string,Node> mp;
    int cnt=0,ord=0;
    while (day<=d){
        cin>>t>>s;
        ord=0;
        for (int i=1;i<=t;i++){
            cin>>name>>id>>con;
            scanf("%d:%d",&h,&m);
            int num=0;
            bool flag=0;
            for (int i=0;i<id.length();i++){
                if (id[i]>='0' && id[i]<='9') num++;
                else flag=1;
            }
            if (flag || num!=18) continue;
            ++ord;
            f[ord].srt=i;
            f[ord].id=id;
            f[ord].name=name;
            f[ord].time=h*60+m;
            if (con==1 && !mp[id].fin)    ++cnt,a[cnt]=name,b[cnt]=id,mp[id].fin=1;
        }
        sort(f+1,f+ord+1,cmp);
        int j=1;
        while (s>0 && j<=ord){
            if (mp[f[j].id].lay && day-mp[f[j].id].lay<=p)    {j++;continue;}
            cout<<f[j].name<<" "<<f[j].id<<endl;
            mp[f[j].id].lay=day;
            j++;
            s--;
        }
        day++;
    }
    for (int i=1;i<=cnt;i++)    cout<<a[i]<<" "<<b[i]<<endl;
}