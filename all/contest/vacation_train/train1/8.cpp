#include <iostream>
#include <algorithm>
using namespace std;
int n,k,S;
struct stu{
    int s;
    int p;
}a[100010];
bool cmp(struct stu& x,struct stu&y){
    if (x.s!=y.s)    return x.s<y.s;
    return x.p<y.p;
}
int main(){
    cin>>n>>k>>S;
    for (int i=0;i<n;i++){
        cin>>a[i].s>>a[i].p;
    }
    sort(a,a+n,cmp);
    int st=0;
    for (int i=0;i<n;i++){
        if (a[i].s<175) st++;
        else break;
    }
    int b[k]={0},cur=0,c[k]={0};
    for (int i=st;i<n;i++){
        if (!c[cur]){
            b[cur]=a[i].s;
            c[cur]+=1;
            cur=(cur+1)%k;
        }
        else if (a[i].s>b[cur] || a[i].s==b[cur] && a[i].p>=S){
            b[cur]=a[i].s;
            c[cur]+=1;
            cur=(cur+1)%k;
        }
    }
    int ans=0;
    for (int i=0;i<k;i++)    ans+=c[i];
    cout<<ans;
}