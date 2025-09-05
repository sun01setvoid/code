//二维
#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0),eps=1e-8;
int sgn(int x){
    if (fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
int dcmp(double x,double y){
    if (fabs(x-y)<eps) return 0;
    else return x<y?-1:1;
}
struct Point{
    int x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator+ (Point B){return Point(x+B.x,y+B.y);}
    Point operator- (Point B){return Point(x-B.x,y-B.y);}
    Point operator* (double k){return Point(x*k,y*k);}
    Point operator/ (double k){return Point(x/k,y/k);}
    bool operator== (Point B) {return sgn(x-B.x)==0 && sgn(y-B.y)==0;}
};
typedef Point Vector;
double Distance(Point A,Point B){return hypot(A.x-B.x,A.y-B.y);}
double Dot (Vector A,Vector B){ return A.x*B.x+A.y*B.y;}//点积
double Len(Vector A){return sqrt(Dot(A,A));}
double Len2(Vector A){return Dot(A,A);}//len**2
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Len(A)/Len(B));}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}//叉积
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}//A为公共点，得到两个向量，平行四边形有向面积
Vector Rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
Vector Normal(Vector A){return Vector(-A.y/Len(A),A.x/Len(A));} //逆时针旋转90°,单位法向量
bool Parallel(Vector A,Vector B){return sgn(Cross(A,B))==0;}
struct Line{
    // p2-p1是方向向量
    Point p1,p2;
    Line(){}
    Line(Point p1,Point p2):p1(p1),p2(p2){}
    Line(Point p,double angle){
        //倾斜角0<=angle<=pi;
        p1=p;
        if (sgn(angle-pi/2)==0){p2=p1+Point(0,1);}
        else{
            p2=p1+Point(1,tan(angle));
        }
    }
    Line(double a,double b,double c){ //ax+by+c=0;
            if (sgn(a)==0){
                p1=Point(0,-c/b);
                p2=Point(1,-c/b);
            }
            else if(sgn(b)==0){
                p1=Point(-c/a,0);
                p1=Point(-c/a,1);
            }
            else{
                p1=Point(0,-c/b);
                p2=Point(1,(-c-a)/b);
            }
    }
};
typedef Line Segment;
int Point_line_relation(Point p,Line v){
    int c=sgn(Cross(p-v.p1,v.p2-v.p1));
    if (c<0) return 1;//p在v的左侧
    if (c>0) return 2;//p在v的右侧
    return 0;
}//点和直线的关系
bool Point_on_seg(Point p,Line v){ //判断是否是钝角，实际上应该是180°
    return sgn(Cross(p-v.p1,v.p2-v.p1))==0 && sgn(Dot(p-v.p1,p-v.p2)<=0);
}//点是否在线段上
bool Dis_point_line(Point p,Line v){
    return fabs(Cross(p-v.p1,v.p2-v.p1))/Distance(v.p1,v.p2);
}//点到直线的距离
Point Point_line_proj(Point p,Line v){
    double k=Dot(v.p2-v.p1,p-v.p1)/Len2(v.p2-v.p1);
    return v.p1+(v.p2-v.p1)*k;
}//点在直线上的投影
Point Point_line_symmetry(Point p,Line v){
    Point q=Point_line_proj(p,v);
    return Point(2*q.x-p.x,2*q.y-p.y);
}//点关于直线的对称点
double Dis_point_seg(Point p,Segment v){
    if (sgn(Dot(p-v.p1,v.p2-v.p1))<0|| sgn(Dot(p-v.p2,v.p1-v.p2))<0)
        return min(Distance(p,v.p1),Distance(p,v.p2));// 点的投影不在线段上，有一个锐角
    return Dis_point_line(p,v);// 点的投影在线段上
}//点到线段的距离
int Line_relation(Line v1,Line v2){
    if (sgn(Cross(v1.p2-v1.p1,v2.p2-v2.p1))==0){
        if (Point_line_relation(v1.p1,v2)==0) return 1;//重合
        else return 0;//平行
    }
    return 2;//相交
}//直线与直线的关系
Point Cross_point(Point a,Point b,Point c,Point d){
    //线段1：ab,   线段2：cd
    double s1=Cross(b-a,c-a),s2=Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
    //要先保证直线AB，CD不共线且不平行
}//直线与直线的交点
bool Cross_segment(Point a,Point b,Point c,Point d){
    double c1=Cross(b-a,c-a),c2=Cross(b-a,d-a);
    double d1=Cross(d-c,a-c),d2=Cross(d-c,b-c);
    return sgn(c1)*sgn(c2)<0 && sgn(d1)*sgn(d2)<0;
}//两条线段是否相交（判断一条线段的端点是否在另一条线段的两侧）  // 但是考虑一个端点在另一条线段上呢
int main(){
    char ch;
    double x[3],y[3];
    Line v[3];
    double ax,ay;
    for (int i=0;i<3;i++) cin>>ch>>x[i]>>ch>>y[i]>>ch;
    getchar();
    cin>>ch>>ax>>ch>>ay>>ch;
    Point ans(ax,ay);
    for (int i=0;i<3;i++) v[i]={{x[i],y[i]},{x[(i+1)%3],y[(i+1)%3]}};
    for (int i=0;i<3;i++) if (ax==x[i] &&ay==y[i]) {cout<<4;return 0;}
    int c[3];
    int res=1;
    int l=0,r=0;
    for (int i=0;i<3;i++)   {
        c[i]=Point_line_relation(ans,v[i]);
        if (c[i]==0) {res=3;break;}
        else if (c[i]==2) r++;
        else l++;
    }
    if (l=3 ||r==3) res=1;
    else if (r>0 && l>0) res=2;
    cout<<res;
    //r==3 || l==3 inside
    //r>0 && l>0 outside
    //r+l==1 bian
    //else dian
}