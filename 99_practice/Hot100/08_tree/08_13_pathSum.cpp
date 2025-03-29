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

// Solution
class Solution {
private:
    void traverse_cal(TreeNode* root, int sum, int targetSum, int& result){
        if(root == NULL) return;

        sum += root->val;
        if(sum == targetSum) result += 1;
        traverse_cal(root->left, sum, targetSum, result);
        sum -= root->val;
        traverse_cal(root->right, sum, targetSum, result);
        sum -= root->val;
    }

    void traverse(TreeNode* root, int targetSum){

    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}