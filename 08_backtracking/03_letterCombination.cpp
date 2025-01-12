#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

// Solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        result.clear();
        str.clear();
        backtracking(digits, 0);

        return result;
    }

private:
    unordered_map<char, string> keyboard = {
        {'2',"abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}

    };

    vector<string> result;
    string str;
    void backtracking(const string& digits, int startIndex){
        if(str.size() == digits.size()){
            result.push_back(str);
            return;
        }
            
        for(int i = 0; i < keyboard[digits[startIndex]].size(); i++){
            str.push_back(keyboard[digits[startIndex]][i]);
            backtracking(digits, startIndex+1);
            str.pop_back();
        }

    }
};

int main(){

    Solution s;

    return 0;
}