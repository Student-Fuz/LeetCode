#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

 

// 示例 1：

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：

// 输入：nums = [1], k = 1
// 输出：[1]

// 时间复杂度O(n*log(k))
class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> max_in_window;

        for(int i = 0; i < k-1; i++)
            window.insert(nums[i]);
        
        for(int i = k-1; i < nums.size(); i++){
            window.insert(nums[i]);
            max_in_window.push_back(*(window.rbegin()));
            window.erase(window.find(nums[i-(k-1)]));
        }

        return max_in_window;
    }
};

// 时间复杂度O(n)----标准答案----关键：单调队列（底层实现双端队列dequeue）
// 关键思路：
// 1. 双端列表中维护着从大到小的值，
// 2. 新进窗口的值会淘汰掉所有窗口内比其小的值
// 3. 判断最大值是否是因时间（窗口移动）而需要被淘汰的值
// 重点：只需要维护有可能成为窗口最大值的元素；没有可能的元素直接淘汰。
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 双端队列，用于存储窗口内元素的索引
        vector<int> max_in_window;

        for (int i = 0; i < nums.size(); i++) {
            // 1. 移除超出窗口左边界的索引
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();  // 删除窗口左边界外的索引
            }

            // 2. 移除队列中比当前元素小的索引
            // 这确保了队列中的元素是递减的，最大值在队头
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();  // 删除比当前元素小的索引
            }

            // 3. 添加当前元素的索引到队列
            dq.push_back(i);

            // 4. 记录当前窗口的最大值（当窗口形成后）
            if (i >= k - 1) {
                max_in_window.push_back(nums[dq.front()]);  // 队头的索引对应的值是窗口最大值
            }
        }

        return max_in_window;
    }
};

// v1_1 双端队列 TODO
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 双端队列，用于存储窗口内元素的索引
        vector<int> max_in_window;


        return max_in_window;
    }
};



int main(){

    Solution s;

    return 0;
}