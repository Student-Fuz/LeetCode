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
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/


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
    void visit(TreeNode* cur, int curDepth, int& maxDepth){
        if(cur == nullptr) return;
        if(cur->left) visit(cur->left, curDepth+1, maxDepth);
        if(cur->right) visit(cur->right, curDepth+1, maxDepth);
        if(cur->left == nullptr && cur->right == nullptr) maxDepth = max(maxDepth, curDepth);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxDepth = 0;
        visit(root, 1, maxDepth);
        return maxDepth;
    }
};

// m1: 递归遍历法--优化
class Solution {
public:
    void visit(TreeNode* cur, int curDepth, int& maxDepth){
        if(cur == nullptr) return;
        if()maxDepth = max(maxDepth, curDepth);
        if(cur->left) visit(cur->left, curDepth+1, maxDepth);
        if(cur->right) visit(cur->right, curDepth+1, maxDepth);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxDepth = 0;
        visit(root, 1, maxDepth);
        return maxDepth;
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