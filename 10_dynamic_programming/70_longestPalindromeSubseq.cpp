#include <bits/stdc++.h>
using namespace std;

// dp定义：dp[i][j]表示范围在[i, j]内字符串最长回文序列长度
// 状态转移：
// 如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
// 如果s[i]与s[j]不相同，dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for(int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }

        for(int i = s.size()-1; i >= 0; i--){
            for(int j = i+1; j < s.size(); j++){
                if(s[i] == s[j]){
                    // 冗余
                    // if(j-1 < i+1){
                    //     dp[i][j] = 2;
                    // }else{
                    //     dp[i][j] = dp[i+1][j-1]+2;
                    // }
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][s.size() - 1];

    }
};

int main() {

    return 0;
}