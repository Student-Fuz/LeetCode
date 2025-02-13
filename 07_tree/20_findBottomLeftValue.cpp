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
// https://leetcode.cn/problems/sum-of-left-leaves/

// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

// 假设二叉树中至少有一个节点。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 循环层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            result = que.front()->val;
            for(int i = 0; i < size; i++){
                if(que.front()->left != nullptr) que.push(que.front()->left);
                if(que.front()->right != nullptr) que.push(que.front()->right);
                que.pop();
            }
            if(que.empty())
                return result;
        }

        return result;

    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}