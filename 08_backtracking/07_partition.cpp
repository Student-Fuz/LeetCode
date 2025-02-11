#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/palindrome-partitioning/

// Solution
class Solution {
private:
    void backtracking(string& s, string subStr, int startIndex, vector<vector<string>>& result, vector<string>& subStrs){
        if(startIndex == s.size()){
            result.push_back(subStrs);
            return;
        }
            
 
        for(int i = startIndex; i < s.size(); i++){
            subStr.push_back(s[i]);
            // 判断从当前索引切断，前半部分是否是回文串
            if(isPalindrome(subStr)){
                subStrs.push_back(subStr);
                backtracking(s, "",  i+1, result, subStrs);
                subStrs.pop_back();
            }
                

        }
    }

    bool isPalindrome(string s){
        if(s.size() == 0)
            return false;
        for(int i = 0; i <= s.size()/2; i++)
            if(s[i] != s[s.size() -1 -i])
                return false;

        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subStrs;
        backtracking(s, "", 0, result, subStrs);
        return result;
    }
};

int main(){

    // Solution s;

    vector<string> subStrs;


    return 0;
}