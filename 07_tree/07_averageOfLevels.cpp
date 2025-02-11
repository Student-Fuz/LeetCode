#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Solution
// m1: 递归遍历法
class Solution {
public:
    void levelVisit(TreeNode* cur, ){

    }
    vector<double> averageOfLevels(TreeNode* root) {
        
    }
};

// 循环遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}