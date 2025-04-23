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
    void traverse(TreeNode* root, int curDepth, int& maxDepth){
        if(root == NULL) return;

        maxDepth = max(maxDepth, curDepth);
        traverse(root->left, curDepth+1, maxDepth);
        traverse(root->right, curDepth+1, maxDepth);
    }
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;

        traverse(root, 1, maxDepth);

        return maxDepth;
    }
};

int main() {

    return 0;
}