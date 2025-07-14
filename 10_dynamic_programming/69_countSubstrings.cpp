#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/palindromic-substrings/description/

// dp 定义：dp[i][j]表示[i, j]可以组成回文串吗？
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        // for(int i = 0; i < s.size(); i++){
        //     dp[i][i] = true;
        // }

        // for(int i = 0; i < s.size(); i++){
        //     for(int j = i; j < s.size(); j++){
        //         if(s[j] == s[i]){
        //             if(j-1 < i+1){
        //                 dp[i][j] = true;
        //             }else{
        //                 dp[i][j] = dp[i+1][j-1];
        //             }
        //         }
        //     }
        // }

        int cnt = 0;
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[j] == s[i]){
                    if(j-1 < i+1){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if(dp[i][j])
                        cnt++;
                }
            }
        }

        return cnt;
    }
};


class Solution {
public:
    int countSubstrings(string s) {
        // dp定义：以s[i-1]结尾的回文串最长长度
        vector<int> dp(s.size()+1, 1);
        int cnt = 0;

        for(int i = 1; i <= s.size(); i++){
            // 情况一：复用上一个字符的回文
            if(i -2 > 0 && i-1-1-dp[i-1-1] > 0 && s[i-1] == s[i-1-1-dp[i-1-1]]){
                dp[i] = dp[i-1]+1;
            }
            // 与上一个字符相同
            if(i-2 > 0 && s[i-1] == s[i-1-1]){
                cnt += 1;
            }
            // 与前第二字符相同
            if(i-3 > 0 && s[i-1] == s[i-1-2]){
                cnt += 1;
            }
            cnt += dp[i];
        }

        return cnt;

    }
};

class Solution {
public:
    int countSubstrings(string s) {
        // dp定义：以s[i-1]结尾的回文串最长长度
        vector<int> dp(s.size(), 1);
        int cnt = 0;

        for(int i = 0; i < s.size(); i++){
            // 情况一：复用上一个字符的回文
            if(i-1 > 0 && i-1-dp[i-1] > 0 && s[i] == s[i-1-dp[i-1]]){
                cnt += 1;
                dp[i] = dp[i-1]+1;
            }
            // // 与上一个字符相同
            // if(i-1 > 0 && s[i] == s[i-1]){
            //     cnt += 1;
            //     dp[i] = max(dp[i], 2);
            // }
            // // 与前第二字符相同
            // if(i-2 > 0 && s[i-1] == s[i-2]){
            //     cnt += 1;
            //     dp[i] = max(dp[i], 3);
            // }
            // cnt += dp[i];
        }

        return cnt;

    }
};

int main() {

    return 0;
}