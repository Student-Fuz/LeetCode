#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include "06_repeatedSubstringPattern.h"

using namespace std;

// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

// 示例 1:

// 输入: s = "abab"
// 输出: true
// 解释: 可由子串 "ab" 重复两次构成。
// 示例 2:

// 输入: s = "aba"
// 输出: false
// 示例 3:

// 输入: s = "abcabcabcabc"
// 输出: true
// 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

// 暴力解法
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool match_flag = false;

        for(int i = 0; i < s.size()/2; i++){
            match_flag = true;
            if(s.size()%(i+1) != 0)
                continue;
            for(int j = 0; j < s.size(); j++){
                
                if(s[j] != s[j % (i+1)]){
                    match_flag = false;
                    break;
                }
            }
            if(match_flag)
                return true;
        }

        return false;
    }
};


// 移动匹配
// s有重复的字符串组成 《==》如果s+s掐头去尾后的字符串中存在s字串
// 充分性易证得；必要性 TODO
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin()); t.erase(t.end() - 1); // 掐头去尾
        if (t.find(s) != std::string::npos) return true; // r
        return false;
    }
};


// KMP TODO
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
    }
};

int main(){

    Solution s;
    string str = "a";

    // cout << str.size();
    // cout << str.size()/2;

    for(int i = 0; i < str.size()/2; i++)
        cout << "hello, world!";
    return 0;
}