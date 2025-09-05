#include <vector>
#include <iostream>
using namespace std;
vector <int> add(vector <int> &A,vector <int> & B){
    vector <int> C;
    int t=0;
    for (int i=0;i<A.size() || i<B.size() || t; i++){
        if (i<A.size()) t+=A[i];
        if (i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    return C;
}
bool cmp(vector <int> &A,vector <int> & B){
    if (A.size()!=B.size()) return A.size()>B.size();
    for (int i=A.size()-1;i>=0;i--)
        if (A[i]!=B[i])
            return A[i]>B[i];
    return true;
}
vector <int> sub(vector <int> &A,vector <int> & B){
    vector <int> C;
    for (int i=0,t=0;i<A.size();i++){
        t=A[i]-t;
        if (i<B.size()) t=t-B[i];
        C.push_back((t+10)%10);
        if (t<0)    t=1;
        else t=0;
    }
    while (C.size()>1 && C.back()==0)   C.pop_back();
    return  C;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector <int>  A,B;
    int flag[2]={0,0};
    for (int i=a.size()-1;i>=0;i--)    {
        if (i==0 && a[i]=='-')    {flag[0]=1;continue;}
        A.push_back(a[i]-'0');
    }
    for (int i=b.size()-1;i>=0;i--)    {
        if (i==0 && b[i]=='-')    {flag[1]=1;continue;}
        B.push_back(b[i]-'0');
    }
    if (flag[0]==0 && flag[1]==1){
        if (cmp(A,B)){
            auto C=sub(A,B);
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
        else{
            auto  C=sub(B,A);
            cout<<"-";
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
    }
    else if (flag[0]==1 && flag[1]==0){
        if (cmp(B,A)){
            auto C=sub(B,A);
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
        else{
            auto  C=sub(A,B);
            cout<<"-";
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
    }
    else  if (flag[1]==1 && flag[0]==1){
        auto  C=add(A,B);
        cout<<"-";
        for (int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    else{
        auto  C=add(A,B);
        for (int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    cout<<endl;
    
    if (flag[0]==0 && flag[1]==1){
        auto C=add(A,B);
        for (int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    else if (flag[0]==1 && flag[1]==0){
        auto C=add(A,B);
        cout<<"-";
        for (int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    else  if (flag[1]==1 && flag[0]==1){
        if (cmp(B,A)){
            auto C=sub(B,A);
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
        else{
            auto  C=sub(A,B);
            cout<<"-";
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
    }
    else{
        if (cmp(A,B)){
            auto C=sub(A,B);
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
        else{
            auto  C=sub(B,A);
            cout<<"-";
            for (int i=C.size()-1;i>=0;i--) cout<<C[i];
        }
    }
    cout<<endl;
}