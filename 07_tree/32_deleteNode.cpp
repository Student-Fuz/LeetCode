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

// 标准答案
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if (root->val == key) {
            // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            if (root->left == nullptr && root->right == nullptr) {
                ///! 内存释放
                delete root;
                return nullptr;
            }
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            else if (root->left == nullptr) {
                auto retNode = root->right;
                ///! 内存释放
                delete root;
                return retNode;
            }
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr) {
                auto retNode = root->left;
                ///! 内存释放
                delete root;
                return retNode;
            }
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
            else {
                TreeNode* cur = root->right; // 找右子树最左面的节点
                while(cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};

// Debug TODO
class Solution {
private:
    void traverse(TreeNode* cur, int key, TreeNode*& pre){
        if(cur == NULL) return;

        if(cur->val == key){
            // 目标节点是左子树节点
            if(pre->val > key){
                // 右子树的最小值作为被删除点
                if(cur->right != nullptr){                  
                    TreeNode* pre_1 = cur->right;
                    TreeNode* replacedNode = cur->right;

                    if(replacedNode->left != nullptr){
                        replacedNode = replacedNode->left;
                        while(replacedNode->left != nullptr){
                            replacedNode = replacedNode->left;
                            pre_1 = pre_1->left;
                        }
                        pre_1->left = nullptr;
                        pre->left = replacedNode;
                        replacedNode->left = cur->left;
                        replacedNode->right = cur->right;
                    }
                    else{
                        cur->right->left = cur->left;
                        pre->left = cur->right;
                    }

                }
                else{
                    pre->left = cur->left;
                }
            }
            // 目标节点是右子树节点
            else if(pre->val < key){
                if(cur->left != nullptr){
                    TreeNode* pre_1 = cur->left;
                    TreeNode* replacedNode = cur->left;

                    if(replacedNode->right != nullptr){
                        replacedNode = replacedNode->right;
                        while(replacedNode->right != nullptr){
                            replacedNode = replacedNode->right;
                            pre_1 = pre_1->right;
                        }
                        pre_1->right = nullptr;
                        pre->right = replacedNode;
                        replacedNode->left = cur->left;
                        replacedNode->right = cur->right;
                    }
                    else{
                        cur->left->right = cur->right;
                        pre->right = cur->left;
                    }

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
            if(root->left != nullptr) {
                TreeNode* target = root->left;
                while(target->right != nullptr)
                    target = target->right;
                target->right = root->right;
                TreeNode* result = root->left;
                delete root;
                return result;
            }
            if(root->right != nullptr){
                TreeNode* target = root->right;
                while(target->left != nullptr)
                    target = target->left;
                target->left = root->left;
                TreeNode* result = root->right;
                delete root;
                return result;
            }
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