//懒得改了
//点集划分和块集划分
//如果用点编号块，那么与点集划分几乎没有区别，要注意最后一个位置
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 200010; // 因为n是1e5，每个矩形两个边，所以最多2e5个事件
struct TrNode {
    long long cover; // 覆盖次数
    long long length; // 区间有效长度
    int tag; // 覆盖标记
} tr[maxn << 2]; // 需要开8倍空间，因为离散化后的点可能有2e5，线段树需要4倍，但实际测试可能需要更多
vector<long long> y_values; // 用于离散化y坐标
struct Scanline {
    long long x, y1, y2;
    int type; // 1表示进入，-1表示离开
    Scanline() {}
    Scanline(long long a, long long b, long long c, int d) : x(a), y1(b), y2(c), type(d) {}
    bool operator<(const Scanline& other) const {
        return x < other.x;
    }
} lines[maxn];
// 离散化查找函数
int find(long long y) {
    return lower_bound(y_values.begin(), y_values.end(), y) - y_values.begin();
}
// 线段树构建和更新函数
void build(int node, int l, int r) {
    tr[node].cover = tr[node].tag = 0;
    if (l == r) { // 叶子节点表示区间[y_values[l], y_values[r])
        tr[node].length = y_values[l+1]-y_values[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid+1, r);
    tr[node].length = tr[node << 1].length + tr[node << 1 | 1].length;
}
void update(int node, int l, int r, int L, int R, int val) {
    if (R <= l || r <= L) return; // 区间无交集
    if (L <= l && r <= R) { // 完全覆盖当前区间
        tr[node].tag += val;
        if (tr[node].tag) tr[node].cover = tr[node].length;
        else tr[node].cover = (l == r) ? 0 : tr[node << 1].cover + tr[node << 1 | 1].cover;
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, L, R, val);
    update(node << 1 | 1, mid+1, r, L, R, val);
    if (tr[node].tag) tr[node].cover = tr[node].length;
    else tr[node].cover = tr[node << 1].cover + tr[node << 1 | 1].cover;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[cnt++] = Scanline(x1, y1, y2, 1);
        lines[cnt++] = Scanline(x2, y1, y2, -1);
        y_values.push_back(y1);
        y_values.push_back(y2);
    }
    // 离散化处理
    sort(y_values.begin(), y_values.end());
    y_values.erase(unique(y_values.begin(), y_values.end()), y_values.end());
    int m = y_values.size();
    y_values.push_back(y_values.back());
    if (m <= 1) { // 所有矩形的y坐标相同或没有矩形
        cout << 0 << endl;
        return 0;
    }
    build(1, 0, m - 1); // 构建线段树，区间[0, m-1)
    sort(lines, lines + cnt);
    long long ans = 0;
    long long prev_x = lines[0].x;
    for (int i = 0; i < cnt; ++i) {
        if (i > 0 && lines[i].x != prev_x) {
            ans += tr[1].cover * (lines[i].x - prev_x);
        }
        prev_x = lines[i].x;
        int l = find(lines[i].y1);
        int r = find(lines[i].y2);
        if (l < r) {
            update(1, 0, m - 1, l, r, lines[i].type);
        }
    }
    cout << ans << endl;
    return 0;
}