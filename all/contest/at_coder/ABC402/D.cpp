#include <iostream>
using namespace std;
const int N=1e6+10;
typedef long long LL;
LL stk[N];
int main(){
  int n,m;
  int a,b;
  cin>>n>>m;
  LL sum=0;
  for (int i=1;i<=m;i++){
    cin>>a>>b;
    stk[(a+b)%n]++;
    sum++;
  }
  sum=sum*(sum-1)/2;
  for (int i=0;i<n;i++){
    if (stk[i]){
      sum-=stk[i]*(stk[i]-1)/2;
    }
  }
  cout<<sum;
}