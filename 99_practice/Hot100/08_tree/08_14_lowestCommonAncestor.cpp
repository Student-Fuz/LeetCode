#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 遇到p是q的祖先或q是p的祖先，并非完全遍历
class Solution {
public:
    TreeNode* visit(TreeNode* cur, TreeNode* p, TreeNode* q){
        if(cur == p || cur == q || cur == NULL) return cur;
        TreeNode* left = visit(cur->left, p, q);
        TreeNode* right = visit(cur->right, p, q);
        if(left != NULL && right != NULL) return cur;
        if(left == NULL && right != NULL) return right;
        if (left != NULL && right == NULL) return left;
        return NULL;
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return visit(root, p, q);
    }
};

int main() {

    return 0;
}