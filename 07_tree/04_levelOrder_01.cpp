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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> thisLevel;
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                thisLevel.push_back(node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(!thisLevel.empty()) result.push_back(thisLevel);
        }

        return result;
    }
};


int main() {

    return 0;
}
