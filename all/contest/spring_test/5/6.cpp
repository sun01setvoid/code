#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t=1;
    cin>>t;
    int d,r,x,y;
    while (t--){
        cin>>d>>r>>x>>y;
        int mi=0x3f3f3f3f;
        if (y>=d) mi=min(int(abs(sqrt((double)x*x+(y-d)*(y-d))-r)+0.5),mi); 
        else if (y<=-d)     mi=min(int(abs(sqrt((double)x*x+(y+d)*(y+d))-r)+0.5),mi);
        else mi=min(abs(x-r),abs(x+r));
        cout<<mi<<endl;
    }
}