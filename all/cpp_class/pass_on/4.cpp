#include <iostream>
#include <vector>
using namespace std;
class Group
{
public:
virtual int add(int x, int y)=0;
virtual int sub(int x, int y)=0;
};
class GroupA : public Group{
    public:
    int add(int x,int y){return x+y;}
    int sub(int x,int y){return x-y;}
};
class GroupB :public Group{
    public:
    int add(int x,int y){return x+y;}
    int sub(int x,int y){
        vector <int> ans;
        for (int i=x%10,j=y%10;x||y;i=x%10,j=y%10){
            ans.push_back((i-j+10)%10);
            x=x/10,y=y/10;
        }
        int tmp=0;
        for (int i=ans.size()-1;i>=0;i--)  tmp=tmp*10+ans[i];
        return tmp;
    }
};
class GroupC: public Group{
public:
    int add(int x,int y){
        vector <int> ans;
        for (int i=x%10,j=y%10;x||y;i=x%10,j=y%10){
            ans.push_back((i+j)%10);
            x=x/10,y=y/10;
        }
        int tmp=0;
        for (int i=ans.size()-1;i>=0;i--)  tmp=tmp*10+ans[i];
        return tmp;
    }
    int sub(int x,int y){
        vector <int> ans;
        for (int i=x%10,j=y%10;x||y;i=x%10,j=y%10){
            ans.push_back((i-j+10)%10);
            x=x/10,y=y/10;
        }
        int tmp=0;
        for (int i=ans.size()-1;i>=0;i--)  tmp=tmp*10+ans[i];
        return tmp;
    }
};
int main(){
    int n;
    int tmp;
    int a[30];
    Group* p[50];
    int cnt=0;
    int s,t;
    char c;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    while (cin>>tmp){
        if (tmp==0) break;
        else {
            cin>>s>>c>>t;
            if (a[tmp]==1)  p[cnt++]=new GroupA;
            else if (a[tmp]==2)  p[cnt++]=new GroupB;
            else p[cnt++]=new GroupC;
            if (c=='-') cout<<p[cnt-1]->sub(s,t)<<"\n";
            else cout<<p[cnt-1]->add(s,t)<<"\n";
        }
    }
}