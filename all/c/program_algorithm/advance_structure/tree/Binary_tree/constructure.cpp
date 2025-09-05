//通过二叉树的前序、中序遍历结果构建二叉树
//后序遍历同操作
#include <bits/stdc++.h>
using namespace std;
struct trnode {
    int val;
    trnode *left;
    trnode *right;
    trnode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    trnode* buildtr(vector<int>& preorder, vector<int>& inorder) {
        // 构建中序遍历的值到索引的映射，方便快速查找
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, 
                     inorder, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> in_map; // 存储中序遍历的值和索引的映射
    trnode* build(vector<int>& preorder, int pre_start, int pre_end,
                   vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }
        // 前序遍历的第一个元素是根节点
        int root_val = preorder[pre_start];
        trnode* root = new trnode(root_val);
        // 在中序遍历中找到根节点的位置
        int in_root = in_map[root_val];
        int left_size = in_root - in_start; // 左子树的节点数量
        // 递归构建左右子树
        root->left = build(preorder, pre_start + 1, pre_start + left_size,
                          inorder, in_start, in_root - 1);//知道了左子树的siz
        root->right = build(preorder, pre_start + left_size + 1, pre_end,
                           inorder, in_root + 1, in_end);//重要的操作,不断递归
        return root;
    }
};
// 辅助函数：打印二叉树（前序遍历）
void printTree(trnode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
signed main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution solution;
    trnode* root = solution.buildtr(preorder, inorder);
    cout << "构建的二叉树前序遍历结果: ";
    printTree(root);
    cout << endl;
    return 0;
}