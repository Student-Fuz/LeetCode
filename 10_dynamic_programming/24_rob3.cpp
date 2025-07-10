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
    vector<int> robTree(TreeNode *root){
        // 0 不偷， 1 偷
        if(root == NULL) return {0, 0};

        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);

        // 1. 偷
        int val1 = root->val + left[0] + right[0];
        // 2. 不偷
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }
    int rob(TreeNode* root) {
        vector<int> vals = robTree(root);
        return max(vals[0], vals[1]);
    }
};

int main() {

    return 0;
}
