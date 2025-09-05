#include <iostream>
using namespace std;
int main(){
  int q[110];
  int hh=0,tt=-1;
  int n;
  cin>>n;
  while (n--){
    int op,tmp;
    cin>>op;
    if (op==1)  {
      cin>>tmp;
      q[++tt]=tmp;
    }
    else {
      cout<<q[hh]<<"\n";
      hh++;
    }
  }
}