#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answers(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                answers[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return answers;
    }
};

int main() {

    return 0;
}