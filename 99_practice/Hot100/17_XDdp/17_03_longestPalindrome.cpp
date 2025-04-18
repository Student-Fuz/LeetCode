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

// 2D dp
// 计算有多少回文子串
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // 情况一 和 情况二
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        // 从下往上、从左往右遍历
        // -> -> ->->
        // -> -> ->
        // -> ->
        // ->
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxlen = 1;
        int begin = 0, end = 0;

        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // 情况一 和 情况二
                        if(j-i+1 > maxlen){
                            maxlen = j-i+1;
                            begin = i;
                            end = j;
                        }
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        if(j-i+1 > maxlen){
                            maxlen = j-i+1;
                            begin = i;
                            end = j;
                        }
                        dp[i][j] = true;
                    }
                }
            }
        }

        return s.substr(begin, maxlen);
    }
};





int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}