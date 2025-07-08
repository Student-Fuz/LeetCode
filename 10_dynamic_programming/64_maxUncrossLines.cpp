#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/uncrossed-lines/description/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // dp数组定义：i，j之前最多能来连多少线(不含i, j)
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp.back().back();
    }
};

int main() {

    return 0;
}