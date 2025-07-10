#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 遍历法
class Solution {
private:
    bool dfs(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        if(left->val != right->val)
            return false;

        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return dfs(root->left, root->right);
    }
};


// 迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q_l;
        queue<TreeNode*> q_r;

        q_l.push(root->left);
        q_r.push(root->right);

        while((!q_l.empty()) && (!q_r.empty())){
            TreeNode* node_l = q_l.front();
            TreeNode* node_r = q_r.front();

            q_l.pop();
            q_r.pop();

            if(node_l == nullptr && node_r == nullptr){
                continue;
            }
            else{
                if(node_l == nullptr || node_r == nullptr){
                    return false;
                }
                else if(node_l->val == node_r->val){
                    q_l.push(node_l->left);
                    q_l.push(node_l->right);
                    q_r.push(node_r->right);
                    q_r.push(node_r->left);
                }
                else
                    return false;
            }
        }

        return true;
    }
};

int main() {

    return 0;
}