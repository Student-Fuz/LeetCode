#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st;

        for(const auto ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            } 
            if(map.find(ch) != map.end() && st.top() == map[ch]){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        
        return st.empty();
    }
};

int main() {

    return 0;
}