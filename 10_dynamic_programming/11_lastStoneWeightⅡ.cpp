#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/last-stone-weight-ii/description/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int target = 0;
        for(int i = 0; i < stones.size(); i++) sum += stones[i];

        target = sum/2;
        vector<int> dp(target+1, 0);
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};

int main() {

    return 0;
}