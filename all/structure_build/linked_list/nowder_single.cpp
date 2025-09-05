#include <iostream>
#include <string>
#include <cstring>
int p[1010],r[1010],e[1010],ne[1010];
using namespace std;
int main(){
    int t,id,d,n,m,cur,pre,idx=1;
    string s;
    int st[1000],top=-1,head=1;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        st[++top]=i;
    }
    memset(ne,-1,sizeof ne);
    for (int i=0;i<m;i++){
        cin>>t>>s;
        pre=head;
        for (cur=head;ne[cur]!=-1;cur=ne[cur]){
            if (e[cur]!=0 && r[e[cur]]!=0 && r[e[cur]]<=t){
                if (cur==head){
                    if (ne[cur]==-1){
                        head=idx;
                    }
                    else head=ne[cur];
                    r[e[cur]]=0;//当然同一个id在同一天也只会有一个预约
                    if (top!=-1){
                        p[e[cur]]=st[top];
                        top--;
                    }//可能这个id已经借过书（绝对没借过,想错了）或者箱子已经空了
                }
                else{
                    ne[pre]=ne[cur];
                    r[e[cur]]=0;
                    if (top!=-1){
                        p[e[cur]]=st[top];
                        top--;
                    }
                }
            }
            pre=cur;
        }
        if (s=="RESERVE"){
            cin>>id>>d;
            if (p[id] || r[id]){
                cout<<"0"<<endl;
            }
            else{
                r[id]=t+d;
                e[idx]=id;
                cur=head;
                while (cur!=-1 && e[cur]!=0 && r[e[cur]]<=t+d){
                    cur=e[cur];
                }
                ne[idx]=cur;
                idx++;
                cout<<"1"<<endl;
            }
        }
        else {
            cin>>id;
            if (s=="BORROW"){
                if (r[id] || p[id] || top==-1) cout<<0<<endl;
                else{
                    p[id]=st[top];
                    cout<<p[id]<<endl;
                    top--;
                }
            }
            else if (s=="RETURN"){
                if (p[id]){
                    cout<<p[id]<<endl;
                    st[++top]=p[id];
                    p[id]=0;
                }
                else    cout<<"0"<<endl;
            }
            else if (s=="QUERY"){
                if (p[id]){
                    cout<<p[id]<<endl;
                }
                else    cout<<"0"<<endl;
            }
        }

    }
}
/*
#include <iostream>
#include <cstring>
using namespace std;
int e[100010],ne[100010],idx=0,head=0;
int find(int x){
    int cur=head;
    while (e[cur]!=x){
        cur=ne[cur];
    }//遍历时间过长,建议用数组O(1)查询
    if (ne[cur]==-1)
        return 0;
    else
        return e[ne[cur]];
}
void insert(int x,int y){
     int cur=head;
    while (e[cur]!=x){
        cur=ne[cur];
    }
    e[idx]=y,ne[idx]=ne[cur],ne[cur]=idx,idx++; 
}
void del(int x){
     int cur=head;
    while (e[cur]!=x){
        cur=ne[cur];
    }
    ne[cur]=ne[ne[cur]];
}
int main(){
    memset(ne,-1,sizeof ne);
    e[idx]=1;
    ne[idx]=-1;
    idx++;
    int n,x,y,q,ans;
    cin>>q;
    for (int i=0;i<q;i++){
        cin>>n;
        if (n==1){
            cin>>x>>y;
            insert(x,y);
        }
        else{
            cin>>x;
            if (n==2){
                ans=find(x);
                cout<<ans<<endl;
            }
            else if (n==3){
                del(x);
            }
        }
    }

}
*/