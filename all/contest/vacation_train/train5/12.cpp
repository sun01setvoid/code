#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
    string f;
    string m;
    string sex;
};
unordered_map <string,Node> p;
bool judge(string a,string b,int num){
    if (a=="-1" || b=="-1" || a=="" || b=="") return true;
    if (p[a].m!="-1" && p[a].m!="" && p[a].m==p[b].m || p[a].f!="" && p[a].f!="-1" && p[a].f==p[b].f)
        return false;
    num++;
    if (num>=5)    return true;
    //因为没有乱伦和隔辈成婚，且是同辈，所以直接看父母
    return judge(p[a].m,p[b].m,num)&&judge(p[a].f,p[b].f,num)&& judge (p[a].m,p[b].f,num) && judge(p[a].f,p[b].m,num);
}
int main(){
    int n,k;
    cin>>n;
    string a,b,c,d;
    for (int i=1;i<=n;i++){
        cin>>a>>b>>c>>d;
        p[a].sex=b;
        p[a].f=c,p[a].m=d;
        p[c].sex="M",p[d].sex="F";//父母的性别，因为下面可能会问
    }
    cin>>k;
    while (k--){
        cin>>a>>b;
        if (p[a].sex==p[b].sex){cout<<"Never Mind"<<endl;continue;}
        cout<<(judge(a,b,1)?"Yes":"No")<<endl;
    }
}