#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        int m = t.size(), n = s.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    // 1. dp意义为匹配到的字符最大数量
                    // dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    // 2. dp意义为从s起始开始匹配到的字符最大数量
                    dp[i][j] = dp[i][j-1];
                }
                if(dp[i][j] == n) return true;
            } 
        }

        return false;
    }
};

int main() {

    return 0;
}
