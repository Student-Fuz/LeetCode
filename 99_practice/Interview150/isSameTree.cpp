#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que_1, que_2;
        que_1.push(p);
        que_2.push(q);

        while(!que_1.empty() && !que_2.empty()){
            int len = que_1.size();

            for(int i = 0; i < len; i++){
                TreeNode* node1 = que_1.front();
                TreeNode* node2 = que_2.front();
                que_1.pop();
                que_2.pop();
                if(node1 == nullptr && node2 == nullptr) continue;
                if(node1 == nullptr || node2 == nullptr) return false;
                if(node1->val != node2->val) return false;
                if(node1 != nullptr) que_1.push(node1->left), que_1.push(node1->right);
                if(node2 != nullptr) que_2.push(node2->left), que_2.push(node2->right);
            }
        }

        return true;
    }
};

int main() {

    return 0;
}