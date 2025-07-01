#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/binary-tree-cameras/description/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* 
 1. 后序遍历
 2. 0--未覆盖
    1--摄像头
    2--被覆盖
*/

class Solution {
private:
    int result = 0;
    int visit(TreeNode* cur){
        if(cur == NULL) return 2;

        int left = visit(cur->left);
        int right = visit(cur->right);
        
        // s1: 左右节点都覆盖了，等着该节点的父节点来覆盖
        if(left == 2 && right == 2) return 0;

        // s2: 左右节点中有未覆盖，该节点要装摄像头
        if(left == 0 || right == 0){
            result++;
            return 1;
        }

        // s3: 左右节点有摄像头，该节点被覆盖
        if(left == 1 || right == 1) return 2;

        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (visit(root) == 0) {
            result++;
        }
        return result;
    }
};

int main() {

    return 0;
}
