#include <iostream>
#include <algorithm>
using namespace std;
class Date{
    protected:
    int  year,month,day;
    public:
    Date(int a,int b,int c):year(a),month(b),day(c){}
};
class Time {
    protected:
    int hour,minute,second;
    public:
    Time(int a,int b,int c):hour(a),minute(b),second(c){}
};
class Schedule: public Date,public Time{
    int ID;
    public :
    Schedule(int a,int b,int c,int d,int e,int f,int g):
    ID(a),Date(b,c,d),Time(e,f,g){}
    bool operator< (const Schedule &s2){
        if (year!=s2.year) return year<s2.year;
        if (month!=s2.month) return month<s2.month;
        if (day!=s2.day) return day<s2.day;
        if (hour!=s2.hour) return hour<s2.hour;
        if (minute!=s2.minute) return minute<s2.minute;
        if (second!=s2.second) return second<s2.second;
        return ID<s2.ID;
    }
    void show(){
        cout<<"The urgent schedule is No."<<ID
        <<": "<<year<<"/"<<month<<"/"<<day<<" "
        <<hour<<":"<<minute<<":"<<second;
    }
};
int main(){
    int id,y,m,d,h,mi,se;
    char c;
    Schedule *p[2000];
    int i;
    for ( i=0;;i++){
        cin>>id;
        if (id==0)    break;
        cin>>y>>c>>m>>c>>d>>h>>c>>mi>>c>>se;
        p[i]=new Schedule(id,y,m,d,h,mi,se);
    }
    for (int j=0;j<i;j++)
        for (int k=0;k<i-j-1;k++){
            if ((*p[k+1])<(*p[k])) swap(p[k],p[k+1]);
    }
    if (i==0) return 0;
    (*p[0]).show();
    return 0;
}