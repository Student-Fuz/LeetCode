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
// https://leetcode.cn/problems/trim-a-binary-search-tree/description/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 标准答案
// 内存泄漏问题？ 树初始化时尽量使用智能指针？
// TODO
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return root;

        if (root->val > high){
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        if (root->val < low){
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        } 

        root->left = trimBST(root->left, low, high); 
        root->right = trimBST(root->right, low, high); 
        return root;
        
    }
};

// 错误代码
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr || root->val < low || root->val > high) return nullptr;
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}