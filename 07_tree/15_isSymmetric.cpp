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
// https://leetcode.cn/problems/invert-binary-tree/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution
// m1: 递归遍历法
class Solution {
public:
    void visit(TreeNode* cur){
        if(cur == nullptr) return;
        
        // 左右两棵子树同时遍历
        
    }
    TreeNode* invertTree(TreeNode* root) {
        visit(root);
        return root;
    }
};



int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}