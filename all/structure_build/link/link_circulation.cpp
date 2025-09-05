#include <stdio.h>
const int N=60;
struct lNode{
    int x;
    int ne;
}Node[N];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int h=-1;
    for (int i=1;i<=n;i++){
        Node[i].x=i,Node[i].ne=-1;
        if (h==-1)    h=i;
        else    Node[i-1].ne=i;
    }
    Node[n].ne=1;//build时last step is link end with head
    int p1=n,p2=h,cnt=0,ord=0;//this time,build p1,because you know(compare single link)
    while (Node[p2].ne!=p2){
        cnt++;
        if (cnt==m){
            ord++;
            printf("No%d: %d\n",ord,p2);
            Node[p1].ne=Node[p2].ne;
            cnt=0;
            p2=Node[p1].ne;
            //p1不变
        }
        else{
            p1=p2;
            p2=Node[p1].ne;
        }
    }
    printf("Last No is: %d",p2);
}