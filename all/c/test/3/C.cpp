#include <iostream>
#include <unordered_map>
char a[100010];
using namespace std;
int main(){
    int t,n,num;
    cin>>t;
    unordered_map <int,int> S;
    for (int i=0;i<t;i++){
        S.clear();
        int cnt2=0,num2=0;
        int cnt4=0,num4=0;
        num=0;
        cin>>a;
        S[0]=1;
        for (int j=0;a[j]!=0;j++){
            if (cnt2<=9 || cnt4<=9){
                if ( a[j]=='2' && cnt2<=9){
                    cnt2++;
                }
                else if( a[j]=='3' && cnt4<=9){
                    cnt4++;
                }
            }
            num=(num*10+a[j]-'0')%9;
        }
        for (int j=0;j<=cnt2;j++)
            for (int v=0;v<=cnt4;v++){
                if (!S.count((j*2+v*6)%9))
                    S[(j*2+v*6)%9]=1;
            }
        if (S.count((9-num)%9)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}