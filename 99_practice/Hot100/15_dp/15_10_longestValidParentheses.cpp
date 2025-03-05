#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/longest-valid-parentheses/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 1)
            return 0;

        int maxLen = 0;
        // val--longestValidParentheses ends in the position (include this postion)
        vector<int> dp(s.size(), 0);

        if(s[1] == ')' && s[0] == '('){
            dp[1] = 2;
            maxLen = 2;
        }
        for(int i = 2; i < s.size(); i++){
            if(s[i] == '(')
                dp[i] = 0;
            else{
                if(s[i-1] == '('){
                    dp[i] = dp[i-2] + 2;
                }
                else{
                    if(i-dp[i-1]-1 >= 0){
                        if(s[i-dp[i-1]-1] == '('){
                            // *** 细节：链接上之前的合法括号
                            // dp[i] = dp[i-1] + 2;
                            if(i-dp[i-1]-2 >= 0)
                                dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2;
                            else
                                dp[i] = dp[i-1] + 2;
                        }
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}