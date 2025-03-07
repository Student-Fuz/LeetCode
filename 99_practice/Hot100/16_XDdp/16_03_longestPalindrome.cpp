#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/longest-palindromic-substring/?envType=study-plan-v2&envId=top-100-liked

// try1
// Solution
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)
            return "";
        int maxLen = 1;
        int targetIndex = 0;

        vector<int> dp(s.size(), 1);

        for(int i = 1; i < s.size(); i++){
            if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == s[i]){
                dp[i] = dp[i-1] + 2;
            }
            maxLen = max(maxLen, dp[i]);
            if(maxLen == dp[i])
                targetIndex = i;
        }

        return s.substr(targetIndex - dp[targetIndex] + 1, maxLen);
    }
};

// try2
// 2D dp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)
            return "";
        int maxLen = 1;
        int targetIndex = 0;

        vector<int> dp(s.size(), 1);

        for(int i = 1; i < s.size(); i++){

            if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == s[i]){
                dp[i] = dp[i-1] + 2;
            }
            maxLen = max(maxLen, dp[i]);
            if(maxLen == dp[i])
                targetIndex = i;
        }

        return s.substr(targetIndex - dp[targetIndex] + 1, maxLen);
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}