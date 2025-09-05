#include <iostream>
#include <queue>
using namespace std;
char a[200010];
int main(){
    int n,t;
    long long suf,k,cnt,num;
    cin>>t;
    for (int i=0;i<t;i++){
        priority_queue <int> q;
        suf=cnt=num=0;
        scanf("%d %d",&n,&k);
        scanf("%s",a);
        for (int j=n-1;j>=1;j--){
            if (a[j]=='1')  suf++;
            else suf--;
            q.push(suf);
        }
        int flag=0;
       while (q.size()){
            int cur=q.top();
            q.pop();
            cnt+=cur;
            num++;
            if (cnt>=k){
                flag=1;
                break;
            }
        }
        if (flag)   cout<<num+1<<endl;
        else cout<<-1<<endl;
    }
}