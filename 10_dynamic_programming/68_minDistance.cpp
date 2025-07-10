#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp数组定义：i-1, j-1结尾（含）的word所需的最小步数
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // dp数组初始化
        for(int i = 0; i < n; i++){
            dp[0][i] = i;
        }
        for(int i = 0; i < m; i++){
            dp[i][0] = i;
        }

        // 状态转移
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+2));
                }
            }
        }

        return dp[m][n];
    }
};

int main() {

    return 0;
}
