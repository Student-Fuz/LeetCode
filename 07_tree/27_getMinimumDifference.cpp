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

// 中序遍历
class Solution {
private:
    // 中序遍历
    void traverse(TreeNode* cur, TreeNode*& pre, int& minVal){
        if(cur == NULL) return;

        traverse(cur->left, pre, minVal);

        if(pre != nullptr && abs(cur->val-pre->val) < minVal) minVal = abs(cur->val-pre->val);
        pre = cur;

        traverse(cur->right, pre, minVal);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minVal = INT_MAX;
        TreeNode* pre = nullptr;
        traverse(root, pre, minVal);
        return minVal;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}