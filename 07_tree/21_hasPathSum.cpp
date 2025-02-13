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
// https://leetcode.cn/problems/sum-of-left-leaves/

// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

// 假设二叉树中至少有一个节点。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 循环层序遍历
class Solution {
public:
    bool visit(TreeNode* cur, int result, int target){
        // 如果是叶子节点
        if(cur->left == nullptr && cur->right == nullptr){
            if(result+cur->val == target)
                return true;
            else
                return false;
        }
        // 前序遍历
        if(cur->left != nullptr)
            if(visit(cur->left, result+cur->val, target)) return true;
        if(cur->right != nullptr)
            if(visit(cur->right, result+cur->val, target)) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return visit(root, 0, targetSum);
    }
};

// 回溯算法 同上


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}