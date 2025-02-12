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
// m1: 递归遍历法
class Solution {
public:
    void visit(TreeNode* cur, vector<vector<int>>& levelResult, int depth){
        if(cur == nullptr) return;
        if(levelResult.size() == depth) levelResult.push_back(vector<int>());
        visit(cur->left, levelResult, depth+1);
        visit(cur->right, levelResult, depth+1);
        levelResult[depth].push_back(cur->val);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> levelResult;
        visit(root, levelResult, 0);
        vector<double> result(levelResult.size(), 0.0);
        for(int i = 0; i < levelResult.size(); i++){
            for(int j = 0; j < levelResult[i].size(); j++){
                result[i] += (double)levelResult[i][j];
            }
            result[i] /= (double)levelResult[i].size();
        }
        return result;
    }
};

// m2:循环遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<double> result;
        while(!que.empty()){
            int size = que.size();
            result.push_back(0.0);
            // 层序遍历
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                result.back() += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        result.back() /= size;
        }
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}