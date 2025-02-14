#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// https://leetcode.cn/problems/merge-two-binary-trees/

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
class Solution {
private:
    TreeNode* traverse(TreeNode* cur, int target){
        if(cur == NULL) return nullptr;

        if(cur->val == target) return cur;
        if(cur->val > target) return traverse(cur->left, target);
        if(cur->val < target) return traverse(cur->right, target);
        return NULL;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return traverse(root, val);
    }
};

// 自写：构建子树
class Solution {
private:
    TreeNode* build(TreeNode* cur){
        if(cur == NULL) return nullptr;

        TreeNode* newNode = new TreeNode(cur->val);

        newNode->left = build(cur->left);
        newNode->right = build(cur->right);

        return newNode;
    }
    TreeNode* traverse(TreeNode* cur, int target){
        if(cur == NULL) return nullptr;

        if(cur->val == target) return build(cur);
        if(cur->val > target) return traverse(cur->left, target);
        if(cur->val < target) return traverse(cur->right, target);
        return NULL;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return traverse(root, val);
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}