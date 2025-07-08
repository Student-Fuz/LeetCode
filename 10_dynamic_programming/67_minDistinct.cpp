#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/distinct-subsequences/description/

class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size()==0) return s.size();

        int m = s.size(), n = t.size();
        int cnt = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] =  dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = dp[i][j-1];
                    // dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                if(dp[i][j] == n) cnt++; 
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}
