#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/unique-binary-search-trees/description/

// 二叉搜索树的定义：
// 对于任意一个节点 N：

// 左子树中所有节点的值都小于节点 N 的值。

// 右子树中所有节点的值都大于节点 N 的值。

// 左右子树也分别是二叉搜索树（递归性质）。

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};

int main() {

    return 0;
}