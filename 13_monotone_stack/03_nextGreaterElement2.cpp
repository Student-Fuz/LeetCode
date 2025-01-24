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
// https://leetcode.cn/problems/next-greater-element-ii/description/

// Solution
// 非循环数组版本
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        stack<int> st;
        vector<int> result(nums.size(), -1);

        st.push(0);

        for(int i = 1; i < nums.size(); i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                result[st.top()] = nums[i]; 
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};

// 循环数组版本
// 思路：拼接两个数组
// 版本一
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        // 拼接数组
        vector<int> nums1(nums.begin(), nums.end());
        nums1.insert(nums1.end(), nums.begin(), nums.end());

        stack<int> st;
        vector<int> result(nums.size(), -1);

        st.push(0);

        for(int i = 1; i < nums1.size(); i++){
            while(!st.empty() && nums1[i] > nums1[st.top()]){
                result[st.top()%nums.size()] = nums1[i]; 
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};

// 版本二
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        stack<int> st;
        vector<int> result(nums.size(), -1);

        st.push(0);

        for(int i = 1; i < nums.size()*2; i++){
            while(!st.empty() && nums[i%nums.size()] > nums[st.top()%nums.size()]){
                result[st.top()%nums.size()] = nums[i%nums.size()]; 
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};


// 循环数组
// 暴力解法
// 时间复杂度O(N^2)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);

        for(int i = 0; i < nums.size(); i++){
            for(int j = (i+1)%nums.size(); j != i; j = (j+1)%nums.size()){
                if(nums[j] > nums[i]){
                    result[i] = nums[j];
                    break;   
                }
            }
        }
        
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}