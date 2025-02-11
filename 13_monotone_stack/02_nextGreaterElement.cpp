#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/next-greater-element-i/

// Solution
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0)
            return {};
        vector<int> result(nums1.size(), -1);
        // val, index
        unordered_map<int, int> nums1_map;

        for(int i = 0; i < nums1.size(); i++)
            nums1_map[nums1[i]] = i;

        stack<int> st;
        st.push(0);
        for(int i = 1; i < nums2.size(); i++){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                if(nums1_map.find(nums2[st.top()]) != nums1_map.end()){
                    result[nums1_map[nums2[st.top()]]] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}