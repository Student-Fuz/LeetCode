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

// dfs法
class Solution {
private:
    void visit(TreeNode* root, vector<vector<int>>& result, int depth){
        if(root == NULL) return;
        if(result.size() == depth) result.push_back({});
        // result[depth].push_back(root->val);
        visit(root->left, result, depth+1);
        // result[depth].push_back(root->val);
        visit(root->right, result, depth+1);
        result[depth].push_back(root->val);

    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        visit(root, result, 0);
        return result;
    }   
};


// 迭代法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;


        while(!q.empty()){
            int curLevelSize = q.size();
            result.push_back({});

            for(int i = 0; i < curLevelSize; i++){
                TreeNode* cur = q.front();

                q.pop();
    
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
    
                result.back().push_back(cur->val);
            }

        }

        return result;
    }
};

int main() {

    return 0;
}