#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// 解答连接
// https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.md

// 给定两个整数数组 inorder 和 postorder ，
// 其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 根据中后序遍历构造二叉树
// 标准答案
// 关键：保持左闭右开原则
class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};

// 链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// 根据前中序列构造二叉树
class Solution {
private:
    TreeNode* traversal (vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;

        TreeNode* root = new TreeNode(preorder.front());

        // 叶子节点
        if(preorder.size() == 1) return root;

        // 根据根节点切割中序遍历
        int delimiterIndex = 0;
        for(; delimiterIndex < inorder.size(); delimiterIndex++){
            if(inorder[delimiterIndex] == root->val) break;
        }

        vector<int> inorder_l(inorder.begin(), inorder.begin()+delimiterIndex);
        vector<int> inorder_r(inorder.begin()+delimiterIndex+1, inorder.end());

        // 根据左右子树大小切割前序遍历
        vector<int> preorder_l(preorder.begin()+1, preorder.begin()+1+inorder_l.size());
        vector<int> preorder_r(preorder.begin()+1+inorder_l.size(), preorder.end());

        root->left = traversal(preorder_l, inorder_l);
        root->right = traversal(preorder_r, inorder_r);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
        return traversal(preorder, inorder);
    }
};


// 链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

// 题解：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solutions/2645281/gen-ju-qian-xu-he-hou-xu-bian-li-gou-zao-6vzt/
// 思路：1. 假设左子树不为空

// 根据前序后序遍历构造树
// 前序和后序遍历构造出的不是唯一二叉树（由多个答案）
class Solution {
    private:
    TreeNode* traversal (vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size() == 0 || postorder.size() == 0) return NULL;

        TreeNode* root = new TreeNode(preorder.front());

        // 叶子节点
        if(preorder.size() == 1) return root;

        // 根据前序遍历的左子树根节点切割后续遍历
        int delimiterIndex = 0;
        for(; delimiterIndex < postorder.size()-1; delimiterIndex++){
            if(postorder[delimiterIndex] == preorder[1]) break;
        }

        vector<int> postorder_l(postorder.begin(), postorder.begin()+delimiterIndex+1);
        vector<int> postorder_r(postorder.begin()+delimiterIndex+1, postorder.begin()+postorder.size()-1);

        vector<int> preorder_l(preorder.begin()+1, preorder.begin()+1+delimiterIndex+1);
        vector<int> preorder_r(preorder.begin()+1+delimiterIndex+1, preorder.end());

        root->left = traversal(preorder_l, postorder_l);
        root->right = traversal(preorder_r, postorder_r);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(preorder, postorder);
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}