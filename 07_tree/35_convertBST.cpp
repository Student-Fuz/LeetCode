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
// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 暴力法
class Solution {
private:
    void traverse(TreeNode* cur){

    }
public:
    TreeNode* convertBST(TreeNode* root) {
        
    }
};

// 反中序遍历
class Solution {
private:
    void traverse(TreeNode* cur, int& sum){
        if(cur == NULL) return;

        traverse(cur->right, sum);

        sum += cur->val;
        cur->val = sum;

        traverse(cur->left, sum);

    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return root;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}