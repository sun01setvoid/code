#include <iostream>
#include <vector>
using namespace std;
typedef pair <long,long> PII;
#define inf 0x7f7f7f7f7f
int main(){
    long long a[4][4],sum;
    int T;
    cin>>T;
    long long x,y,z;
    long long xi,yi;
    for (int v=0;v<T;v++){
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                a[i][j]=inf;
        int jiao=0,zh=0;
        vector <PII> addi;
        int flag;
        for (int k=0;k<3;k++){
            cin>>x>>y>>z;
            if ( x==2 && y==2)  sum=3*z;
            else {
                if (x!=2 && y!=2)   jiao++;  
                else    {
                    zh++;
                    if (x==2)   flag=1;
                    else flag=0;
                }
                addi.push_back({x,y});
            }
            a[x][y]=z;
        }
        for (int i=0;i<(int)addi.size();i++){
            xi=addi[i].first,yi=addi[i].second;
            a[4-xi][4-yi]=sum-a[2][2]-a[xi][yi];
        }
        if (jiao==2){
            for (int i=1;i<=3;i++)
                for (int j=1;j<=3;j++)
                    if (i!=j && (i==2 || j==2))
                        a[i][j]=(sum-z)/2;
        }
        else if (zh==2){
              for (int i=1;i<=3;i++)
                for (int j=1;j<=3;j++)
                    if (i!=2 && j!=2 && (i+j==4 || i==j))
                        a[i][j]=(sum-z)/2;
        }
        else{
            int su=0;
            if (flag==1){
                for (int i=1;i<=3;i++){
                    su=0;
                    if (i==2)   continue;
                    for (int j=1;j<=3;j++)
                        if (a[j][i]==inf)
                            xi=j,yi=i;
                        else
                            su+=a[j][i];
                    a[xi][yi]=sum-su;                           
                }
                for (int i=1;i<=3;i++){
                    su=0;
                    if (i==2)   continue;
                    for (int j=1;j<=3;j++)
                        if (a[i][j]==inf)
                            xi=i,yi=j;
                        else
                            su+=a[i][j];
                    a[xi][yi]=sum-su;                           
                }
            }
            else{
                for (int i=1;i<=3;i++){
                    su=0;
                    if (i==2)   continue;
                    for (int j=1;j<=3;j++)
                        if (a[i][j]==inf)
                            xi=i,yi=j;
                        else
                            su+=a[i][j];
                    a[xi][yi]=sum-su;                           
                }
                for (int i=1;i<=3;i++){
                    su=0;
                    if (i==2)   continue;
                    for (int j=1;j<=3;j++)
                        if (a[j][i]==inf)
                            xi=j,yi=i;
                        else
                            su+=a[j][i];
                    a[xi][yi]=sum-su;                           
                }
            }
        }
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                cout<<a[i][j]<<" ";
        cout<<endl;
    }
}