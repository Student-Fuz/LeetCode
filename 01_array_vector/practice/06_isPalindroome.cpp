#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

// 字母和数字都属于字母数字字符。

// 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。


class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v_s;
        for(char char_s : s){
            if((char_s >= 'a' && char_s < 'z') || (char_s >= 'A' && char_s <= 'Z'))
                v_s.push_back(tolower(char_s));
        }
        for(int i = 0; i < v_s.size()/2; i++){
            if(v_s[i] != v_s[v_s.size()-1-i])
                return false;
        }
        return true;
    }
};

int main(){

    Solution s;

    return 0;
}