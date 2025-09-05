#include <iostream>
using namespace std;
const int N=2e5+10;
int a[N],stk[N];
int main(){
    int t;
    int n,q;
    cin>>t;
    while (t--){
        cin>>n>>q;
        for (int i=1;i<=n;i++)  cin>>a[i],stk[a[i]]=i;
        int l,r,k;
        while (q--){
            cin>>l>>r>>k;
            int cnt1=0,cnt2=0;
            int res1=0,res2=0;
            if (stk[k]<l || stk[k]>r){
                cout<<-1<<" ";continue;
            }
            while (l<=r){
                int mid=l+r>>1;
                if (mid==stk[k]) break;
                else if (mid<stk[k]){
                    if (a[mid]>k){
                        cnt1++;
                    }
                    else res1++;
                    l=mid+1;
                }
                else{
                    if (a[mid]<k){
                        cnt2++;
                    }
                    else res2++;
                    r=mid-1;
                }
            }
            if (cnt1<=k-1-res1 && cnt2<=n-k-res2){
                cout<<(max(cnt1,cnt2)-min(cnt1,cnt2))*2+min(cnt1,cnt2)*2<<" ";
            }else{
                cout<<-1<<" ";
            }
        }
        cout<<"\n";
    }
}