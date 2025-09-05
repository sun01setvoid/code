//条件，两两之间知道关系
//因为此题知道每一个元素之间的关系，所以直接用入度来排序就好(在他前的有几个，其他的都是在他之后)，不需要遍历拓扑，当然拓扑也就O(n+m)
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct p{
    int idx;
    int score;
}pe[1010];
bool cmp(struct p& a,struct p& b){
    return a.score>b.score;
}
int main(){
    int t,n,temp;
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)  pe[i].idx=i;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                scanf("%1d",&temp);
                if (temp)  {
                    if (i<j) pe[i].score++,pe[j].score--;
            
                }
                else{
                   if (i>j) pe[i].score++,pe[j].score--;
                }
            }
        }
        sort(pe+1,pe+n+1,cmp);
        for (int i=1;i<=n;i++)  cout<<pe[i].idx<<" ";
        cout<<endl;
        for (int i=1;i<=n;i++)  pe[i].score=0;
    }
}
//tip2
//直接根据有边，没边排序