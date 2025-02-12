#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/


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
// m1: 转置结果数组
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
        result[depth].push_back(cur->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<vector<int>> result_r;
        int depth = 0;
        order(root, result, depth);
        for(int i = 0; i < result.size(); i++)
            result_r.push_back(result[result.size()-1-i]);
        return result_r;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}