#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string removeExtraSpace(string s){
        string result;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(!result.empty() && result.back() != ' ')
                    result.push_back(s[i]);
            }
            else{
                result.push_back(s[i]);
            }
        }

        if(result.back() == ' ') result.pop_back();
        return result;
    }

    string reverseWords(string s) {
        // step1: 倒序整个string
        int l = 0, r = s.size()-1;
        while(l < r){
            swap(s[l++], s[r--]);
        }

        // step2: 去除多余空格
        s = removeExtraSpace(s);

        // step3: 翻转单词
        int begin = 0, end = 0;

        for(; end <= s.size(); end++){
            if(s[end] == ' ' || end == s.size()){
                int l = begin, r = end-1;
                while(l < r){
                    swap(s[l++], s[r--]);
                }
                begin = end+1;
            }
        }

        return s;
    }
};

int main() {

    Solution s;

    string str = s.removeExtraSpace(" hello  world  ");

    cout << str;

    return 0;
}