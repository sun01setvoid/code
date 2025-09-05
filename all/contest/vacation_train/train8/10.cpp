#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[1000010];
struct Node{
    string id;
    int sum;
    int num;
}sch[5010];
int main(){
    int n,c,tmp;
    int cur=1;
    cin>>n>>c;
    string s;
    vector <int> ans;
    for (int i=1;i<=n;i++){
        cin>>s>>tmp;
        sch[i].id=s;
        sch[i].sum=tmp;
        while (sch[i].sum>=c){
            if (p[cur]==0)    sch[i].sum-=c,cur++,sch[i].num++;
        }
        if (sch[i].sum){
            ans.push_back(sch[i].sum);
            sch[i].sum=0;
            sch[i].num++;
        }
    }
    for (int i=1;i<=n;i++)    cout<<sch[i].id<<" "<<sch[i].num<<endl;
    sort(ans.begin(),ans.end(),greater <int>());
    vector <int> rem;
    for (int i=0;i<ans.size();i++){
        if (rem.size()){
            for (auto it=rem.begin();it<rem.end();it++){
                if (ans[i]<=c-p[*it]){
                    p[*it]+=ans[i],ans[i]=0;
                    if (p[*it]==c)    rem.erase(it);
                    break;
                }
            }
        }
        if (ans[i])    p[cur]+=ans[i],ans[i]=0,rem.push_back(cur),cur++;
    }
    cout<<cur-1;
}