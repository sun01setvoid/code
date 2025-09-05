#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define pa pair<int,int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr<<#x<<'='<<(x)<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int z=2e5+10;
const int zz=2e5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const ld pi=3.141592653589793;
const ld eps=1e-8;

// 判断x的符号（考虑浮点误差）
int sgn(ld x){
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}

// 比较两个浮点数x和y的大小（考虑浮点误差）
int dcmp(ld x,ld y){
    if(fabs(x-y)<eps)return 0;
    return x>y?1:-1;
}

// 定义二维点/向量结构体
struct Point{
    double x,y;
    double angle;
    int id;
    Point(){}
    Point(double _x,double _y){x = _x; y = _y;}
    
    /// 向量加法
    Point operator + (const Point b) const{return Point( x+b.x,y+b.y );}
    /// 向量减法
    Point operator - (const Point b) const{return Point( x-b.x,y-b.y );}
    /// 向量数乘
    Point operator * (const double k) const{return Point(k*x,k*y);}
    /// 向量数除
    Point operator / (const double k) const{return Point(x/k , y/k);}
    
    // 判断两点是否相等
    bool operator == (const Point b) const{return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;}
    // 用于排序：先按x排序，x相同再按y排序
    bool operator < (const Point b) const {return sgn(x-b.x)==0?sgn(y-b.y)<0:x<b.x;}
    
    /// 点积
    double operator * (const Point b) const{return x*b.x + y*b.y;}
    /// 叉积
    double operator ^ (const Point b) const{return x*b.y - y*b.x;}
    
    /// 两点之间的距离
    double distance(const Point P) const {return hypot(x-P.x,y-P.y);}
    /// 向量长度
    double len(){return hypot(x,y);}
    /// 长度的平方
    double len2(){return x*x + y*y;}
    
    /// 化为长度为 r 的向量
    Point trunc(double r){
        double l = len();
        r /= l;
        return Point(x*r,y*r);
    }
    
    /// 计算以当前点p为中心，pa到pb的夹角大小
    double rad(Point a,Point b){
        Point p = *this;
        return fabs( atan2( fabs( (a-p)^(b-p) )  , (a-p)*(b-p) ) );
    }
    
    /// 绕p点逆时针旋转angle角度
    Point rotate(Point p,double angle){
        Point v = (*this) - p;
        double c = cos(angle) , s = sin(angle);
        return Point(p.x + v.x * c - v.y * s , p.y + v.x *s + v.y * c);
    }
    
    ///逆时针旋转90度
    Point rotleft(){return Point(y,-x);}
    ///顺时针旋转90度
    Point rotright(){return Point(y,-x);}
};

// 点积函数
double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// 叉积函数
double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// 点比较函数，用于排序
bool cmpPoint(Point a,Point b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// 求点集的凸包（使用Andrew算法）
vector<Point> getHull(vector<Point> P) {
    sort(P.begin(), P.end(),cmpPoint);
    vector<Point> hull;
    
    // 分两次扫描（下凸包和上凸包）
    for (int phase = 0; phase < 2; ++phase) {
        int start = hull.size();
        for (auto &p : P) {
            // 当凸包中至少有两个点，且新点使凸包不再保持凸性时，弹出最近的点
            while (hull.size() >= start + 2 &&
                   cross(hull[hull.size() - 2] - p, hull.back() - p) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        hull.pop_back(); // 删除重复添加的最后一个点
        reverse(P.begin(), P.end()); // 反转点集以处理上凸包
    }
    return hull;
}

// 计算凸包面积（使用鞋带公式）
double arHull(const vector<Point>& g) {
    double s = 0.0;
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        s += g[i].x * g[j].y - g[i].y * g[j].x;
    }
    return fabs(s) * 0.5;
}

// 计算凸包周长
double ceHull(const vector<Point>& g) {
    double len = 0;
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        Point t=g[j]-g[i];
        len+=t.len(); // 累加每条边的长度
    }
    return len;
}

void solve(){
    int n;cin>>n; // 矩形数量
    double a,b,r;cin>>b>>a>>r; // 输入矩形的长、宽和圆角半径（注意：这里先输入b再输入a）
    
    a-=2*r;b-=2*r; // 调整矩形尺寸，减去圆角直径
    
    vector<Point>p; // 存储所有矩形的四个角点（考虑旋转后）
    
    for(int i=0;i<n;i++){
        double x,y,ag;cin>>x>>y>>ag; // 矩形中心坐标和旋转角度
        Point t,res,ct;
        ct.x=x;ct.y=y; // 中心点
        
        // 计算矩形四个角点（未旋转前）
        t.x=x-a/2;t.y=y-b/2;
        res=t.rotate(ct,ag); // 绕中心点旋转
        p.pb(res);
        
        t.x=x+a/2;t.y=y-b/2;
        res=t.rotate(ct,ag);
        p.pb(res);
        
        t.x=x+a/2;t.y=y+b/2;
        res=t.rotate(ct,ag);
        p.pb(res);
        
        t.x=x-a/2;t.y=y+b/2;
        res=t.rotate(ct,ag);
        p.pb(res);
    }
    
    // 计算所有点的凸包
    vector<Point>Hull=getHull(p);
    
    // 计算总周长：凸包周长 + 圆角的周长（2πr）
    double ans=ceHull(Hull)+pi*r*2;
    
    // 输出结果，保留两位小数
    cout<<fixed<<setprecision(2)<<ans<<endl;
}

signed main(){
    IOS;
    int t=1;
    //cin>>t;
    while(t--)solve();
}