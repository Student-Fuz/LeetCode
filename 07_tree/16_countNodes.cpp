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
// https://leetcode.cn/problems/count-complete-tree-nodes/description/

// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
// 若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。


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
class Solution {
public:
    void visit(TreeNode* cur, int& nums){
        // 后序遍历
        if(cur == NULL) return;

        visit(cur->left, nums);
        visit(cur->right, nums);
        nums += 1;
        
    }
    int countNodes(TreeNode* root) {
        int nums = 0;
        visit(root, nums);
        return nums;
    }
};


// m2: 循环遍历
// 利用完全二叉树特性优化 TODO
class Solution {
public:
    int countNodes(TreeNode* root) {
        int nums = 0;

        return nums;
    }
};



int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}