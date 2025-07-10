#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // key--val, val--index
        unordered_map<int, int> numMap;

        for(int i = 0; i < nums1.size(); i++){
            numMap[nums1[i]] = i;
        }

        stack<int> st;
        vector<int> result(nums1.size(), -1);

        for(const auto& num : nums2){
            while(!st.empty() && st.top() < num){
                if(numMap.find(st.top()) != numMap.end())
                    result[numMap[st.top()]] = num;
                st.pop();
            }
            st.push(num);
        }

        return result;
    }
};

int main() {

    return 0;
}