#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 小顶堆
        priority_queue<int, vector<int>, greater<>> min_heap;

        for(const auto num : nums){
            min_heap.push(num);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        return min_heap.top();
    }
};

int main() {

    return 0;
}