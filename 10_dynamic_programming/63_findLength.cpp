#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/

// dp数组定义：dp[i][j]:从i,j开始的最长公共数组长度
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen;
    }
};


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);
        int maxLen = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[j] = dp[j + 1] + 1;
                    maxLen = max(maxLen, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }

        return maxLen;
    }
};

// dp数组定义：从到i,j为止最长公共数组的长度（不含i，j）
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxLen = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen;
    }
};

// 滚动数组
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n+1, 0);
        int maxLen = 0;

        for(int i = 1; i <= m; i++){
            for(int j = n; j >= 1; j--){
                if(nums1[i-1] == nums2[j-1]){
                    dp[j] = dp[j-1] + 1;
                }else{
                    dp[j] = 0;
                }
                maxLen = max(maxLen, dp[j]);
            }
        }

        return maxLen;
    }
};

// 暴力
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLen = 0;
        vector<int>& numsl = nums1;
        vector<int>& numsb = nums2;
        if(nums1.size() > nums2.size()){
            numsl = nums2;
            numsb = nums1;
        }

        for(int i = 0; i < numsb.size(); i++){
            for(int j = 0; j < numsl.size(); j++){
                if(numsl[j] == numsb[i]){
                    int len = 1;
                    while(j-len >= 0 && i-len >= 0 && numsl[j-len] == numsb[i-len])
                        len++;
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};

int main() {

    return 0;
}
