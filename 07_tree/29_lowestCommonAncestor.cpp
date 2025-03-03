#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 标准答案：
// 后序遍历
class Solution {
private:
    TreeNode* postorder(TreeNode* cur, TreeNode* p, TreeNode* q){
        if(cur == p || cur == q || cur == NULL) return cur;
        TreeNode* left = postorder(cur->left, p, q);
        TreeNode* right = postorder(cur->right, p, q);
        if(left != NULL && right != NULL) return cur;
        if(left == NULL && right != NULL) return right;
        if (left != NULL && right == NULL) return left;
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return postorder(root, p, q);
    }
};

// 标准答案优化版
class Solution {
private:
    TreeNode* postorder(TreeNode* cur, TreeNode* p, TreeNode* q){
        if(cur == p || cur == q || cur == NULL) return cur;
        TreeNode* left = postorder(cur->left, p, q);
        TreeNode* right = postorder(cur->right, p, q);
        if(left != NULL && right != NULL) return cur;
        if(left == NULL) return right;
        return left;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return postorder(root, p, q);
    }
};

// 暴力前序
// 前序遍历
// 迷途知返
class Solution {
private:
    void isAncestor(TreeNode* cur, TreeNode* p, TreeNode* q, int& findNums){
        if(cur == NULL) return;

        if(cur->val == p->val) findNums++;
        if(cur->val == q->val) findNums++;

        if(findNums == 2) return;

        isAncestor(cur->left, p, q, findNums);
        isAncestor(cur->right, p, q, findNums);

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {


    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}