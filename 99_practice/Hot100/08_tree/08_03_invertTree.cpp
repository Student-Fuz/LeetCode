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
private:
    void visit(TreeNode* root){
        if(root == NULL) return;

        swap(root->left, root->right);
        visit(root->left);
        visit(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        visit(root);
        return root;
    }
};

int main() {

    return 0;
}