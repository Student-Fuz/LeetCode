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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return{};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qSize = q.size();
            int maxVal = INT_MIN;

            for(int i = 0; i < qSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                maxVal = max(maxVal, node->val);
            }

            result.push_back(maxVal);
        }

        return result;
    }
};

int main() {

    return 0;
}
