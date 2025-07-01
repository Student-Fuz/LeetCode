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

void dfs(TreeNode* node){
    if(node == NULL) return;

    swap(node->left, node->right);
    dfs(node->left);
    dfs(node->right);

}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 前序
        dfs(root);
        return root;
    }
};

int main() {

    return 0;
}
