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
                    r[e[cur]]=0;
                    if (top!=-1 && p[e[cur]]==0){
                        p[e[cur]]=st[top];
                        top--;
                    }//可能这个id已经借过书或者箱子已经空了
                }
                else{
                    ne[pre]=ne[cur];
                    r[e[cur]]=0;
                    if (top!=-1 && p[e[cur]]==0){
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
                ne[idx]=idx+1;
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
#include <string>
#include <cstring>
int p[1010],r[1010],e[1010],ne[1010];
using namespace std;
int main(){
    int t,id,d,n,m,cur,pre,idx=0;
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
        for (cur=head;cur!=-1;cur=ne[cur]){
            if (e[cur]!=0 && r[e[cur]]!=0 && r[e[cur]]<=t){
                if (cur==head){
                    if (ne[cur]==-1){
                        head=idx+1;
                    }
                    else head=ne[cur];
                    r[e[cur]]=0;
                    if (top!=-1){
                        p[e[cur]]=st[top];
                        top--;
                    }
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
                ne[idx]=idx+1;
                e[++idx]=id;//因为前面是更新head=idx+1，那这样的话其实我在更新head+1的位置
                ne[idx]=-1;
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
*/