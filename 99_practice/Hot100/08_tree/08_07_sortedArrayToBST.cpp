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

// 二分分配
class Solution {
private:
    TreeNode* visit(const vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int mid = (left + right)/2;
        TreeNode* cur = new TreeNode(nums[mid]);

        cur->left = visit(nums, left, mid-1);
        cur->right = visit(nums, mid+1, right);
        return cur;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return visit(nums, 0, nums.size()-1);
    }
};

int main() {

    return 0;
}