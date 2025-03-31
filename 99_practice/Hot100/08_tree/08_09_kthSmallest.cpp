#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked


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
    void traverse(TreeNode* root, int& k, int& target){
        if(root == NULL) return;

        traverse(root->left, k, target);
        k -= 1;
        if(k == 0) target = root->val;
        traverse(root->right, k, target);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int target = 0;
        traverse(root, k, target);
        return target;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    int k=0;
    cout << k-- << endl;

    return 0;
}