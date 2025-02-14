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
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// 解答连接
// https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.md

// 给定两个整数数组 inorder 和 postorder ，
// 其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// code1 错误
class Solution {
private:
    bool traverse(TreeNode* cur){
        // 叶子节点
        if(cur->left == nullptr && cur->right == nullptr)
            return true;
        // 该节点出现违背
        if(cur->left != nullptr && cur->val <= cur->left->val)
            return false;
        if(cur->right != nullptr && cur->val >= cur->right->val)
            return false;


        if(cur->left == nullptr){
            return traverse(cur->right);
        }
        else if(cur->right == nullptr){
            return traverse(cur->left);
        }
        else{
            return traverse(cur->left) && traverse(cur->right);
        }
        
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return traverse(root);
    }
};

// code2 暴力验证
class Solution {
private:
    // 递归判断左侧的子树值是否比根节点小
    bool traverse_l(TreeNode* cur, int target){
        if(cur == NULL) return true;
        if(cur->val >= target) return false;
        if(traverse_l(cur->left != nullptr?cur->left:nullptr, target)) 
            return traverse_l(cur->left != nullptr?cur->left:nullptr, cur->val); 
        else return false;
    }
    // 递归判断右侧的子树值是否比根节点大
    bool traverse_r(TreeNode* cur, int target){
        if(cur == NULL) return true;
        if(cur->val <= target) return false;
        if(traverse_r(cur->right != nullptr?cur->right:nullptr, target)) 
            return traverse_r(cur->right != nullptr?cur->right:nullptr, cur->val);
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return traverse_l(root->left, root->val) && traverse_r(root->right, root->val);
    }
};

// 标准答案
class Solution {
    public:
        TreeNode* pre = NULL; // 用来记录前一个节点
        bool isValidBST(TreeNode* root) {
            if (root == NULL) return true;
            bool left = isValidBST(root->left);
    
            if (pre != NULL && pre->val >= root->val) return false;
            pre = root; // 记录前一个节点
    
            bool right = isValidBST(root->right);
            return left && right;
        }
    };

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}