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
// 自写，递归法
class Solution {
private:
    void traversal(vector<TreeNode*> cur, vector<vector<int>>& result){
        if(cur.size() == 0)
            return;
        vector<TreeNode*> next;
        vector<int> curLevelVal;

        for(TreeNode* node : cur){
            if(node->left != NULL) next.push_back(node->left);
            if(node->right != NULL) next.push_back(node->right);
            curLevelVal.push_back(node->val);
        }
        result.push_back(curLevelVal);
        traversal(next, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> result;
        traversal({root}, result);
        return result;
    }
};

// 递归法 标准答案 
class Solution {
public:
    // 前序访问
    // void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    // {
    //     if (cur == nullptr) return;
    //     if (result.size() == depth) result.push_back(vector<int>());
    //     result[depth].push_back(cur->val);
    //     order(cur->left, result, depth + 1);
    //     order(cur->right, result, depth + 1);
    // }

    // 中序访问
    // void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    // {
    //     if (cur == nullptr) return;
    //     if (result.size() == depth) result.push_back(vector<int>());
    //     order(cur->left, result, depth + 1);
    //     result[depth].push_back(cur->val);
    //     order(cur->right, result, depth + 1);
    // }

    // 后序访问
    void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
        result[depth].push_back(cur->val);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}