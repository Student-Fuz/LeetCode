#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/diameter-of-binary-tree/?envType=study-plan-v2&envId=top-100-liked

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution
class Solution {
private:
    void inorderTraverse(TreeNode* root, vector<int>& result){
        if(root == NULL) return;

        inorderTraverse(root->left, result);

        result.push_back(root->val);

        inorderTraverse(root->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        inorderTraverse(root, result);

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}