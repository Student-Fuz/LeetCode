#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/diameter-of-binary-tree/?envType=study-plan-v2&envId=top-100-liked

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution
// 树的直径等于每个节点为根的左右树的深度和的最大值
// 后序遍历
class Solution {
private:
    int traverse(TreeNode* root, int& dia){
        if(root == NULL){
            return 0;
        }

        int L = traverse(root->left, dia);
        int R = traverse(root->right, dia);

        dia = max(dia, L+R);
        return max(L, R)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        traverse(root, dia);
        return dia;
    }
};

// 标准答案
class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}