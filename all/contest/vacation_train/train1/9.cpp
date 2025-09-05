#include <iostream>
using namespace std;
int ans[1010][10];
int st[30];
int a[1010];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int top=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int j=0,cur1=0,cur2=0;
    while (j!=n || top!=0){
        if (top==0){
            if (j<n && (cur2==0 || a[j]<=ans[cur1][cur2-1])){
                ans[cur1][cur2]=a[j];
                cur2++,j++;
                if (cur2==k)    cur1++,cur2=0;
            }
            else if(j<n && a[j]>ans[cur1][cur2-1]){
                    st[++top]=a[j];
                    j++;
            }
        }
        else{
            if (cur2==0 || st[top]<=ans[cur1][cur2-1]){
                ans[cur1][cur2]=st[top--];
                cur2++;
                if (cur2==k)    cur1++,cur2=0;
            }
            else if(st[top]>ans[cur1][cur2-1]){
                if (j<n && (cur2==0 || a[j]<=ans[cur1][cur2-1])){
                    ans[cur1][cur2]=a[j];
                    cur2++,j++;
                    if (cur2==k)    cur1++,cur2=0;
                }
                else if(j<n && a[j]>ans[cur1][cur2-1]){
                    if (top+1<=m){
                        st[++top]=a[j];
                        j++;
                    }
                    else   cur1++,cur2=0;
                }
                else cur1++,cur2=0;
            }
        }
    }
    for (int i=0;i<=cur1;i++){
        if (ans[i][0])    cout<<ans[i][0];
        for (int j=1;j<k;j++){
            if (ans[i][j])  cout<<" "<<ans[i][j];
        }
        if (ans[i][0])    cout<<endl;
    }
}