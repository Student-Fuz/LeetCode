#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() < k) return {};
        // 存索引
        deque<int> deq;
        vector<int> result;

        for(int i = 0; i < k; i++){
            while(!deq.empty() && nums[deq.back()] <= nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
        }
        result.push_back(nums[deq.front()]);
        
        for(int i = k; i < nums.size(); i++){
            if(!deq.empty() && deq.front() == i-k)
                deq.pop_front();
            while(!deq.empty() && nums[deq.back()] <= nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
            result.push_back(nums[deq.front()]);
        }

        return result;
    }
};

int main() {

    return 0;
}