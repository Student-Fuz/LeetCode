#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(const auto ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if(st.top() == ch){
                while(!st.empty() && st.top() == ch){
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }

        string result(st.size(), ' ');
        int n = st.size();
        for(int i = n-1; i >= 0; i--){
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

int main() {

    return 0;
}