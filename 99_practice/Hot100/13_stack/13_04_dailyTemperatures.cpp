#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/daily-temperatures/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                res[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};

int main() {

    return 0;
}