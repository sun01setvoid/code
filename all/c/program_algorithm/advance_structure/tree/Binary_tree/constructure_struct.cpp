// 通过二叉树的前序、中序遍历结果构建二叉树
// 后序遍历同操作
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
struct trnode
{
    int left;
    int right;
    trnode() : left(-1), right(-1) {}
} tr[maxn];
class Solution
{
public:
    int buildtr(vector<int> &preo, vector<int> &ino)
    {
        for (int i = 0; i < ino.size(); ++i)
        {
            in_map[ino[i]] = i;
        }
        return build(preo, 0, preo.size() - 1,
                     ino, 0, ino.size() - 1);
    }

private:
    unordered_map<int, int> in_map;
    int build(vector<int> &preo, int pst, int pen,
              vector<int> &ino, int ist, int ien)
    {
        if (pst > pen || ist > ien)
        {
            return -1;
        }
        int rt_val = preo[pst];
        int rt_pos = in_map[rt_val];
        int lesiz = rt_pos - ist;
        tr[rt_val].left = build(preo, pst + 1, pst + lesiz,
                                ino, ist, rt_pos - 1);
        tr[rt_val].right = build(preo, pst + lesiz + 1, pen,
                                 ino, rt_pos + 1, ien);
        return rt_val;
    }
};
void printTr(int rt)
{
    if (rt == -1)
        return;
    cout << rt << " ";
    printTr(tr[rt].left);
    printTr(tr[rt].right);
}
signed main()
{
    vector<int> preo = {3, 9, 20, 15, 7};
    vector<int> ino = {9, 3, 15, 20, 7};
    Solution solution;
    int rt = solution.buildtr(preo, ino);
    cout << "构建的二叉树前序遍历结果: ";
    printTr(rt);
    cout << endl;
    return 0;
}