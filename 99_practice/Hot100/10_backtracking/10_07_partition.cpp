#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/palindrome-partitioning/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    void backtracking(const string& s, string subStr, int startIndex, vector<vector<string>>& result, vector<string>& subStrs){
        if(startIndex == s.size()){
            result.push_back(subStrs);
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            subStr.push_back(s[i]);
            if(isPalindrome(subStr)){
                subStrs.push_back(subStr);
                backtracking(s, "", i+1, result, subStrs);
                subStrs.pop_back();
            }
        }
    };

    bool isPalindrome(string& s){
        int l = 0, r = s.size()-1;
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> subStrs;
        vector<vector<string>> result;
        backtracking(s, "", 0, result, subStrs);
        return result;
    }
};

int main() {

    return 0;
}