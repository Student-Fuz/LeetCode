#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/reverse-words-in-a-string/description/

class Solution {
private:
    string removeExtraSpace(string s){
        // 双指针
        int slow = 0, fast = 0;

        for(; fast < s.size(); fast++){
            
        }
    }
public:
    string reverseWords(string s) {
        // step1: 倒序整个string
        int l = 0, r = s.size()-1;
        while(l < r){
            swap(s[l], s[r]);
        }

        // step2: 去除多余空格


    }
};

int main() {

    return 0;
}