#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sliding-window-maximum/?envType=study-plan-v2&envId=top-100-liked

// 相关段子：
// 能力再强，时间到了，也就退了
// 总有更年轻的取代能力不够的老员工
// 我悟了，队尾只要有更年轻（i越靠后）同时还能力更强（数值越大）的，留着其他比它更早入职同时能力却更差的没有什么意义，统统开了；队首的虽然能力最强，但是年龄最大，一旦发现它超过年龄范围（不在滑动窗口的范围内），不用看能力就可以直接开了。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 维护一个对应元素递减的双端队列
        deque<int> deq;
        vector<int> maxInWindow;

        for(int i = 0; i < nums.size(); i++){
            // 1. 清除被窗口位置淘汰的值
            if(!deq.empty() && deq.front() == i-k)
                deq.pop_front();

            // 2. 清除之前比自己小的值
            while(!deq.empty() &&nums[deq.back()] < nums[i])
                deq.pop_back();

            // 3. 插入当前值
            deq.push_back(i);

            if(i >= k -1)
                maxInWindow.push_back(nums[deq.front()]);
        }
        return maxInWindow;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}