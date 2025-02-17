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
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 利用搜索二叉树特点进行遍历
class Solution {
private:
    // 中序遍历
    void traverse(TreeNode* cur, TreeNode*& pre, vector<int>& result, int& curFreq, int& maxFreq){
        if(cur == NULL) return;

        traverse(cur->left, pre, result, curFreq, maxFreq);

        if(pre != NULL && cur->val == pre->val){
            curFreq++;
        }
        else{
            curFreq = 1;
        }
        if(curFreq > maxFreq){
            maxFreq = curFreq;
            result.clear();
            result.push_back(cur->val);
        }
        else if(curFreq == maxFreq){
            result.push_back(cur->val);
        }
        pre = cur;

        traverse(cur->right, pre, result, curFreq, maxFreq);

    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        TreeNode* pre = nullptr;
        int curFreq = 0;
        int maxFreq = 0;
        traverse(root, pre, result, curFreq, maxFreq);
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}