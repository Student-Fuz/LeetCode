#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;

        for(int i = 0; i <= s.size(); i++){
            for(int j = 0; j < wordDict.size(); j++){
                if(i >= wordDict[j].size() && dp[i - wordDict[j].size()]){
                    string substr = string(s.begin()+i-wordDict[j].size(), s.begin()+i);
                    if(substr == wordDict[j])
                        dp[i] = true; 
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {



    return 0;
}
