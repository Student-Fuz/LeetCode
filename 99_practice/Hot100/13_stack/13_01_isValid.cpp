#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/valid-parentheses/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {']' , '['},
            {'}', '{'},
            {')', '('}
        };
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(map.find(s[i]) == map.end()){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    if(st.top() == map[s[i]]){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {

    return 0;
}