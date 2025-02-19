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
// https://leetcode.cn/problems/insert-into-a-binary-search-tree/

// 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 从上向下遍历，无前中后序之分
// 找到正确的空节点插入即可 
class Solution {
private:
    TreeNode* traverse(TreeNode* cur, int val){
        if(cur == NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if(val < cur->val) cur->left = traverse(cur->left, val);
        if(val > cur->val) cur->right = traverse(cur->right, val);

        return cur;

    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return traverse(root, val);
    }
};

// 优化版
class Solution {
private:
    void traverse(TreeNode* cur, int val, TreeNode*& pre){
        if(cur == NULL){
            TreeNode* newNode = new TreeNode(val);
            if(val > pre->val) pre->right = newNode;
            else pre->left = newNode;
            return;
        }

        pre = cur;
        if(val < cur->val) traverse(cur->left, val, pre);
        if(val > cur->val) traverse(cur->right, val, pre);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode* pre = nullptr;
        traverse(root, val, pre);
        return root;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}