#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums2(nums.begin(), nums.end());
        nums2.insert(nums2.end(), nums.begin(), nums.end());

        stack<int> st;
        vector<int> result(nums.size(), -1);
        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                result[st.top()%nums.size()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};

int main() {

    return 0;
}