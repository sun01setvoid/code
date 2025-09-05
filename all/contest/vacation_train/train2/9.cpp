#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,m,s;
    int op,cnt=0;
    char stk[10];
    int top=0;
    char a[10][10];
    int l[10][2]={0};
    char res[100010];
    cin>>n>>m>>s;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        l[i][1]=strlen(a[i]);
    }
    while (cin>>op){
        if (op==-1)    break;
        if (op==0){
            if (top!=0)    res[cnt]=stk[top--],cnt++;
        }
        else{
            if (top==s){
                res[cnt]=stk[top--],cnt++;
                if (l[op][0]!=l[op][1]){
                    stk[++top]=a[op][l[op][0]];
                    l[op][0]++;
                }
            }
            else{
                if (l[op][0]!=l[op][1]){
                    stk[++top]=a[op][l[op][0]];
                    l[op][0]++;
                }
            }
        }
    }
    for (int i=0;i<cnt;i++)    cout<<res[i];
}