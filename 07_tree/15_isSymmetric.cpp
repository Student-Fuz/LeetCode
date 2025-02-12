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
// m1: 循环遍历，同时对比
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que_l;
        queue<TreeNode*> que_r;

        if(root == NULL) return false;

        que_l.push(root->left);
        que_r.push(root->right);

        while((!que_l.empty()) && (!que_r.empty())){
            if(que_l.size() != que_r.size()) return false;
            int size = que_l.size();

            for(int i = 0; i < size; i++){
                if((que_l.front() != nullptr) && (que_r.front() != nullptr))
                {   
                    // 注意此处必须加{}
                    if(que_l.front()->val != que_r.front()->val) return false;
                }
                // if(que_l.front()->val != que_r.front()->val) return false;
                else if(que_l.front() != nullptr || que_r.front() != nullptr) return false;  
                      
                if(que_l.front() != nullptr){
                    que_l.push(que_l.front()->left);
                    que_l.push(que_l.front()->right);
                } 
                if(que_r.front() != nullptr){
                    que_r.push(que_r.front()->right);
                    que_r.push(que_r.front()->left);
                } 

                que_l.pop();
                que_r.pop(); 

            }
        }

        return true;
    }
};

// 标准答案
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val) return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
        bool isSame = outside && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};



int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}