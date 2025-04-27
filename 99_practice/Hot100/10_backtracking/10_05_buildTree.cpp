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
    TreeNode* traversal (vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        
        // 1. 找到根节点
        int rootVal = preorder[0];

        TreeNode* root = new TreeNode(rootVal);

        if(preorder.size() == 1) return root;

        // 2. 在中序遍历中找到根节点
        int index = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == rootVal){
                index = i;
                break;
            }
        }

        // 3.1 分割中序遍历
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());

        // 3.2 分割前序遍历
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+index);
        vector<int> rightPreorder(preorder.begin()+1+index, preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return NULL;
        return traversal(preorder, inorder);
    }
};

// 内存+时间优化版本
class Solution {
private:
    TreeNode* traversal (vector<int>& preorder, vector<int>& inorder, int begin_p, int end_p, int begin_i, int end_i) {
        if (begin_p >= end_p) return NULL;
        
        // 1. 找到根节点
        int rootVal = preorder[begin_p];

        TreeNode* root = new TreeNode(rootVal);

        if(preorder.size() == 1) return root;

        // 2. 在中序遍历中找到根节点
        int index = 0;
        for(; index < end_i; index++){
            if(inorder[begin_i + index] == rootVal){
                break;
            }
        }

        // 3.1 分割中序遍历
        int begin_i_l = begin_i;
        int end_i_l = begin_i + index;

        int begin_i_r = begin_i + index + 1;
        int end_i_r = end_i;

        // 3.2 分割前序遍历
        int begin_p_l = begin_p + 1;
        int end_p_l = begin_p + 1 + index;

        int begin_p_r = begin_p + 1 + index;
        int end_p_r = end_p;

        root->left = traversal(preorder, inorder, begin_p_l, end_p_l, begin_i_l, end_i_l);
        root->right = traversal(preorder, inorder, begin_p_r, end_p_r, begin_i_r, end_i_r);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return NULL;
        return traversal(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};

int main() {

    return 0;
}