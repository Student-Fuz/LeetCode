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


// 错误用例 [-2147483648]
class Solution {
private:
    bool visit(TreeNode* cur, int& preVal){
        if(cur == NULL) return true;

        bool left = visit(cur->left, preVal);
        if(cur->val <= preVal) return false;
        preVal = cur->val;
        bool right = visit(cur->right, preVal);
        return left&&right;
    }

public:
    bool isValidBST(TreeNode* root) {
        int preVal = INT_MIN;
        return visit(root, preVal);
    }
};

class Solution {
private:
    bool visit(TreeNode* cur, TreeNode*& pre){
        if(cur == NULL) return true;

        bool left = visit(cur->left, pre);
        if(pre != NULL && cur->val <= pre->val) return false;
        pre = cur;
        bool right = visit(cur->right, pre);
        return left && right;
    }

public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return visit(root, pre);
    }
};

int main() {

    return 0;
}