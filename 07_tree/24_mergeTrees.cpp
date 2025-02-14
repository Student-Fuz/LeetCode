#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// https://leetcode.cn/problems/merge-two-binary-trees/

// Definition for a binary tree node.
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
    TreeNode * traverse(TreeNode* node1, TreeNode* node2){
        // 前序遍历
        if(node1 == NULL && node2 == NULL) return nullptr;

        TreeNode* newNode = new TreeNode(0);

        if(node1 == NULL) newNode->val += node2->val;
        else if(node2 == NULL) newNode->val += node1->val; 
        else newNode->val += node1->val + node2->val;

        newNode->left = traverse((node1!=NULL?node1->left:nullptr), (node2!=NULL?node2->left:nullptr));
        newNode->right = traverse((node1!=NULL?node1->right:nullptr), (node2!=NULL?node2->right:nullptr));

        return newNode;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return traverse(root1, root2);
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}