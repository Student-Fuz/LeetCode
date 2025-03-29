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
// 非原地
class Solution {
private:
    void traverse(TreeNode* root, vector<TreeNode*>& nodeList){
        if(root == NULL) return;

        nodeList.push_back(root);
        traverse(root->left, nodeList);
        traverse(root->right, nodeList);

    }

public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        std::vector<TreeNode*> nodeList;

        traverse(root, nodeList);

        for(int i = 0; i < nodeList.size()-1; i++){
            nodeList[i]->left = NULL;
            nodeList[i]->right = nodeList[i+1];
        }
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}