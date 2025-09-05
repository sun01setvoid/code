#include <bits/stdc++.h>
using namespace std;
char a[100];
int main()
{
  int num=0;
  cin>>a;
   for (int j=0;a[j]!=0;j++){
      num=(num*10+a[j])%9;
      }
      cout<<num;
  }
 
