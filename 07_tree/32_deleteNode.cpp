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
// https://leetcode.cn/problems/delete-node-in-a-bst/description/

// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

// 一般来说，删除节点可分为两个步骤：

// 首先找到需要删除的节点；
// 如果找到了，删除它。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void traverse(TreeNode* cur, int key, TreeNode*& pre){
        if(cur == NULL) return;

        if(cur->val == key){
            // 目标节点是左子树节点
            if(pre->val > key){
                // 右子树的最小值作为被删除点
                if(cur->right != nullptr){

                    pre->left = ;

                }
                else{
                    pre->left = cur->left;
                }
            }
            // 目标节点是右子树节点
            else if(pre->val < key){
                if(cur->left != nullptr){
                    pre->right = cur->left;
                }
                else{
                    pre->right = cur->right;
                }
            }
            delete cur;
            return;
        }

        pre = cur;
        if(key < cur->val) traverse(cur->left, key, pre);
        if(key > cur->val) traverse(cur->right, key, pre);

    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return nullptr;
        // 删除根节点
        if(root->val == key){
            if(root->left != nullptr) return root->left;
            if(root->right != nullptr) return root->right;
            return nullptr;
        }
        // 不删除根节点
        TreeNode* pre = nullptr;
        traverse(root, key, pre);
        return root;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}