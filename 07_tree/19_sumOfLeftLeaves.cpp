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

// 给定二叉树的根节点 root ，返回所有左叶子之和。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归
class Solution {
public:
    void visit(TreeNode* cur, bool leftFlag, int& result){
        if(cur == NULL) return;

        if(leftFlag){
            if(!cur->left && !cur->right){
                result += cur->val;
                return;
            }
        }

        visit(cur->left, true, result);
        visit(cur->right, false, result);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        visit(root, false, result);
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}