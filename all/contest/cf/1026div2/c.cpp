#include <iostream>
#include <queue>
using namespace std;
const int N=2e5+10;
typedef pair<int,int> PII;
int arr[N];
PII q[N];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,a,b;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>arr[i];
        for (int i=1;i<=n;i++){
            cin>>a>>b;
            q[i].first=a,q[i].second=b;
        }
        int l=0,r=0;
        bool f=1;
        queue <int> dq;
        for (int i=1;i<=n;i++){
            if (arr[i]==-1) r+=1,dq.push(i);
            else l+=arr[i],r+=arr[i];
            if (q[i].first>r || q[i].second<l){f=0;break;}
            else{
                //cout<<"l="<<l<<" r="<<r<<" l1="<<q[i].first<<" r1="<<q[i].second<<endl;
                if (r>q[i].second){
                    for (int j=1;j<=r-q[i].second;j++){
                        dq.pop();
                    }
                }
                if (l<q[i].first){
                    for (int j=1;j<=q[i].first-l;j++){
                        int tmp=dq.front();
                        dq.pop();
                        arr[tmp]=1;
                    }
                }
                r=min(r,q[i].second);
                l=max(l,q[i].first);
            }
        }
        if (!f) cout<<-1<<endl;
        else{
            for (int i=1;i<=n;i++){
                if (arr[i]==-1) cout<<0<<" ";
                else cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}