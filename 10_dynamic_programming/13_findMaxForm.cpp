#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/ones-and-zeroes/

// 返回值--背包中的物品最大数量
// 不能用贪心
// 无限个0 2个1
// {110， 1000， 1000}
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < strs.size(); i++){
            int zeroNum = 0;
            int oneNum = 0;

            for(auto& ch : strs[i]){
                if(ch == '0') zeroNum++;
            }
            oneNum = strs[i].size() - zeroNum;

            for(int j = m; j >= zeroNum; j--){
                for(int k = n; k >= oneNum; k--){
                    dp[j][k] = max(dp[j][k], dp[j-zeroNum][k-oneNum] + 1);
                }
            }
        }

        return dp[m][n];

    }
};

int main() {

    return 0;
}
