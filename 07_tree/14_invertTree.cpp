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
// https://leetcode.cn/problems/invert-binary-tree/


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
// m1: 递归遍历法
class Solution {
public:
    void visit(TreeNode* cur){
        // 交换当前节点的左右两个节点
        if(cur == nullptr) return;
        // 错误做法：交换值
        if(cur->left != nullptr && cur->right != nullptr) swap(cur->left->val, cur->right->val);
    }
    TreeNode* invertTree(TreeNode* root) {
        visit(root);
        return root;
    }
};

// m1: 递归遍历法
class Solution {
public:
    void visit(TreeNode* cur){
        // 交换当前节点的左右两个节点
        if(cur == nullptr) return;
        // m1-前序
        // swap(cur->left, cur->right);
        // if(cur->left != nullptr) visit(cur->left);
        // if(cur->right != nullptr) visit(cur->right);

        // m2-中序 (不成立)
        // if(cur->left != nullptr) visit(cur->left);
        // swap(cur->left, cur->right);
        // if(cur->right != nullptr) visit(cur->right);

        // m3-后序 
        if(cur->left != nullptr) visit(cur->left);
        if(cur->right != nullptr) visit(cur->right);
        swap(cur->left, cur->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        visit(root);
        return root;
    }
};

// m2:循环遍历 TODO
// class Solution {
// public:  
//     Node* connect(Node* root) {
//         queue<Node*> que;
//         if(root == NULL) return root;
//         que.push(root);
//         while(!que.empty()){
//             int size = que.size();
//             Node* cur;
//             for(int i = 0; i < size; i++){
//                 // 下一层节点
//                 if(que.front()->left != nullptr) que.push(que.front()->left);
//                 if(que.front()->right != nullptr) que.push(que.front()->right);
//                 // 连接操作
//                 cur = que.front();
//                 que.pop();
//                 cur->next = que.front();
//             }
//             cur->next = NULL;
//         }
//         return root;
//     }
// };


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}