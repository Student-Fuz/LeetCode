#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=top-100-liked

// // Solution
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length(), n = text2.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         for (int i = 1; i <= m; i++) {
//             char c1 = text1.at(i - 1);
//             for (int j = 1; j <= n; j++) {
//                 char c2 = text2.at(j - 1);
//                 if (c1 == c2) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };
















// 自写
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}