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
// https://leetcode.cn/problems/balanced-binary-tree/description/

// 给定一个二叉树，判断它是否是 平衡二叉树
// 平衡二叉树 是指该树所有节点的左右子树的高度相差不超过 1。
  
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
    void traverse(TreeNode* cur, vector<vector<int>>& paths, vector<int> path) {
        if(cur == NULL) return;

        // 前序遍历
        path.push_back(cur->val);
        if(cur->left == NULL && cur->right == NULL) paths.push_back(path);
        traverse(cur->left, paths, path);
        traverse(cur->right, paths, path);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<vector<int>> paths;
        vector<int> path;
        traverse(root, paths, path);
        for(int i = 0; i < paths.size(); i++){
            result.push_back("");
            for(int j = 0; j < paths[i].size(); j++){
                result.back() += to_string(paths[i][j]);
                result.back() += "->";
            }
            if(result.back().length() > 2)
                result.back().erase(result.back().length() - 2);
        }
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}