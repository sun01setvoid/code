#include <iostream>
#include <cstring>
using namespace std;
int n;
const int N=50010;
int tr[N];
int lowbit(int x){
    return x & -x;
}
void add(int x,int c){
    for (int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;    
}
int sum(int x){
    int res=0;
    for (int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
int main(){
    int a,b,suml,sumr,t,temp;
    string s;
    cin>>t;
    for (int j=0;j<t;j++){
        cin>>n;
        memset(tr,0,sizeof tr);
        for (int i=1;i<=n;i++){
            cin>>temp;
            add(i,temp);       
        }
        while (cin>>s){
            if (s=="End")   {cout<<endl;break;}
            else {
                cin>>a>>b;
                if(s=="Add"){
                   add(a,b);      
                }
                else if (s=="Sub"){
                    add(a,-b);
                }
                else{
                    suml=sum(a-1);
                    sumr=sum(b);
                    cout<<sumr-suml<<endl;        
                }
            }
        }
    }
}