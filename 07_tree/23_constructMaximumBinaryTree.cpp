#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// https://leetcode.cn/problems/maximum-binary-tree/description/

// 给定两个整数数组 inorder 和 postorder ，
// 其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归构建
class Solution {
private:
    TreeNode* construct(vector<int>& nums){
        if(nums.size() == 0) return NULL;

        TreeNode* root = new TreeNode(0);

        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        root->val = nums[maxIndex];
        vector<int> nums_l(nums.begin(), nums.begin()+maxIndex);
        vector<int> nums_r(nums.begin()+maxIndex+1, nums.end());

        root->left = construct(nums_l);
        root->right = construct(nums_r);

        return root;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums);
    }
};

// 优化？ TODO

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}