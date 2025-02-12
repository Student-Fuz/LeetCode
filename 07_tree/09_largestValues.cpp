#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>

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
// m1: 递归遍历
// class Solution {
// public:
//     void order(TreeNode* cur, vector<vector<int>>& result, int depth)
//     {
//         if (cur == nullptr) return;
//         if (result.size() == depth) result.push_back(vector<int>());
//         order(cur->left, result, depth + 1);
//         order(cur->right, result, depth + 1);
//         result[depth].push_back(cur->val);
//     }
//     vector<vector<int>> largestValues(TreeNode* root) {
//         vector<vector<int>> result;
//         vector<vector<int>> result_r;
//         int depth = 0;
//         order(root, result, depth);

//     }
// };

// m2: 循环遍历
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if(root == NULL) return result;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            int maxVal = que.front()->val;
            for(int i = 0; i < size; i++){
                maxVal = max(maxVal, que.front()->val);
                if(que.front()->left != nullptr) que.push(que.front()->left);
                if(que.front()->right != nullptr) que.push(que.front()->right);
                que.pop();
            }
            result.push_back(maxVal);
        }
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}